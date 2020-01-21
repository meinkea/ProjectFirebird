%main
%Version 4 of Orange Team Flyout Sim
%Contributors:
%William "Mikhaila" Gregory
%Christopher Opificius
clc;
clear;
close all;
%constants 
load('aeroData.mat'); %Aerodynamic data
elevator_setting = input('In degrees, set the elevator deflection.--->'); %Setting the elevator angle
thetag = input('In degrees, set the glide pitch angle.--->'); %degrees (pitch angle for glide phase)
alphatrim = trim(elevator_setting,alpha,cm); %degrees(the alpha value for trimmed conditions)
m0 = 0.167; %kg (inital mass)
mf = 0.1566; %kg (final mass)
tb = 0.840; %seconds (burn time)
drail = distdim(3,'ft','m'); %meters
dt = 0.005; %time interval
%Setting initial conditions
%Setting initial values
i = 1;
%Setting first entry into arrays
t(1) = 0; %seconds
Lift(1) = 0; %Newtons
Drag(1) = 0; %Newtons
Moment(1) = 0; %Newton-meters
V(1) = 0; %meters per second
h(1) = 0; %meters
d(1) = 0; %meters
theta(1) = 60; %degrees
gamma(1) = 60; %degrees
a(1) = 0; %alpha in degrees
hr = drail*sind(theta(1)); %rail height in meters
dr = drail*cosd(theta(1)); %rail distance in meters
%Preventing code from back tracking to other phases
OnRail = true;
BoostFlight = true;
Transition = true;
Glide = false;
%Simulation
while h(i) >= -0.0000000000001
   
    if h(i) < hr && d(i) < dr && t(i) < tb && OnRail == true%Boost Rail Phase
    theta(i) = theta(1);
    gamma(i) = gamma(1); %Overwriting the gamma value found
    a(i) = a(1);
    %Sets of if statments to prevent the glider from phasing through the
    %stand.
    if V(i) <0 
        V(i) = 0;
    end
    if h(i) <0 
        h(i) = 0;
    end
    if d(i) < 0 
        d(i) = 0;
    end
    thrust = thrustcurve(t(i)); %Finding thrust at current time
    m = ((tb-t(i))/tb)*(m0-mf)+mf; %Finding mass at current time
    fprintf('In boost rail phase! Height is %d and range is %d \n',h(i),d(i))
    elseif t(i) <= tb && d(i) > dr && BoostFlight == true%Boost flight phase
    OnRail = false; %Rail can no longer be used
    a(i) = alphatrim; %Setting new alpha value
    theta(i) = gamma(i) + a(i); %Finding new theta
    thrust = thrustcurve(t(i)); %Finding thrust at current time
    m = ((tb-t(i))/tb)*(m0-mf)+mf; %Finding mass at current time
    fprintf('In boost flight phase! Height is %d and range is %d \n',h(i),d(i))
    elseif theta(i) >= thetag && t(i) > tb && Transition == true%Transitional phase
    BoostFlight = false;
    thrust = 0; %No thrust
    m = mf; %Constant mass
    a(i) = alphatrim;
    theta(i) = gamma(i) + a(i);%Finding new theta
    if theta(i) <= thetag %Transitioning to glide phase when this is true.
        Transition = false;
        Glide = true;
    end
    fprintf('In transitional phase! Height is %d and range is %d \n',h(i),d(i))
    elseif Glide == true %Glide phase
    Transition = false; 
    theta(i) = thetag; %Setting constant theta
    thrust = 0; %No thrust
    m = mf; %Constant mass
    a(i) = theta(i) - gamma(i); %Finding new alpha
    fprintf('In glide phase! Height is %d and range is %d \n',h(i),d(i))
    end
    [q,L,D,M] = aeroPred(a(i),V(i),S,c,alpha,cl,cd,cm,elevator_setting); %Grabbing Aero predicitons
    [Vel,path,alt,down] = twoddata(thrust,a(i),gamma(i),V(i),D,L,m,g,dt,h(i),d(i)); %Integrating
    %Storing new values
    V(i+1) = Vel; %Velocity
    h(i+1) = alt; %Height
    d(i+1) = down; %Distance
    theta(i+1) = theta(i); %Pitch angle
    gamma(i+1) = path; %Flight Path angle
    a(i+1) = a(i); %Angle of attack
    Lift(i+1) = L; %Lift
    Drag(i+1) = D; %Drag
    Moment(i+1) = M; %Moment
    %Propigate
    t(i+1) = t(i) + dt;
    i = i+1; 
    %Ending the simulation if glider goes past start point.
    if d(i) < 0
        break;
    end
end
fprintf('Simulation complete! Generating plots... \n');
%3D Plot
%{
figure 
plot3(d,side,h)
grid on 
title('3D flight path')
xlabel('Downrange Distance (m)')
ylabel('Siderange Distance (m)')
zlabel('Altittude (m)')
%}
%2D Version of 3D Plot
figure 
plot(d*3.28084,h*3.28084)
grid on
title('Altittude vs. Downrange Distance')
xlabel('Downrange Distance (ft)')
ylabel('Altittude (ft)')
%Velocity
figure
plot(t,V*3.28084)
grid on
title('Velociy vs. Time')
ylabel('Velocity (ft/s)')
xlabel('Time (s)')
%Angles
%Pitch and Flight Path
figure 
plot(t,gamma,t,theta)
grid on
title('Flight Path Angle and Pitch Angle vs. Time')
ylabel('Gamma and Theta (degrees)')
xlabel('Time (s)')
%Angle of Attack
figure 
plot(t,a)
grid on
title('Angle of Attack vs. Time')
ylabel('Angle of Attack (degrees)')
xlabel('Time (s)')
%{
%Lift and Drag
figure
plot(t,Lift,t,Drag)
grid on

%Roll
figure 
plot(t,roll)
grid on
title('Roll vs. Time')
ylabel('Roll (degrees)')
xlabel('Time (s)')
%Yaw

figure 
plot(t,yaw)
grid on
title('Yaw vs. Time')
ylabel('Yaw (degrees)')
xlabel('Time (s)')
%}
fprintf('Plots generated! Ending program...')
