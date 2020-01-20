%main
%Version 3 of Orange Team Flyout Sim
clc;
clear;
close all;
%constants 
load('aeroData.mat'); %Aerodynamic data
V0 = 0; %meters / second
theta0 = degtorad(60); %degrees
gamma0 = degtorad(60); %degrees
side0 = 0; %meters
d0 = 0; %meters
h0 = 0; %meters
yaw0 = degtorad(0); %degrees
roll0 = degtorad(0); %degrees
alpha0 = degtorad(0); %degrees
alphatrim = degtorad(-0.06776); %degrees(the alpha value for trimmed conditions)
thetag = degtorad(-1); %degrees (pitch angle for glide phase)
m0 = 0.167; %kg (inital mass)
mf = 0.1566; %kg (final mass)
tb = 0.840; %seconds (burn time)
drail = distdim(3,'ft','m'); %meters
hr = drail*sin(theta0); %rail height in meters
dr = drail*cos(theta0); %rail distance in meters
dt = 0.005; %time interval
%Setting initial conditions
%Setting initial values
m = m0; 
i = 1;
V1 = V0;
h1 = h0;
d1 = d0;
gamma1 = gamma0;
alpha1 = alpha0;
side1 = 0;
%Setting first entry into arrays
t(1) = 0;
q1(1) = 0;
L1(1) = 0;
D1(1) = 0;
M1(1) = 0;
V(1) = V0;
h(1) = h0;
d(1) = d0;
roll(1) = roll0;
yaw(1) = yaw0;
theta(1) = theta0;
gamma(1) = gamma0;
a(1) = alpha0;
side(1) = 0; %Sideways displacement
%Simulation
while h(i) >= -0.1
   
    if h1 < hr && d1 < dr && t(i) < tb %Boost Rail Phase
    theta1 = theta0; 
    [q,L,D,M] = aeroPred(alpha1,V1,S,c,alpha,cl0,cd0,cm0); %Grabbing Aero predicitons
    thrust = thrustcurve(t(i)); %Finding thrust at current time
    m = ((tb-t(i))/tb)*(m0-mf)+mf; %Finding mass at current time
    [V1,gamma1,h1,d1] = twoddata(thrust,alpha1,gamma1,V1,D,L,m,g,dt,h1,d1); %Integrating
    gamma1 = gamma0; %Overwriting the gamma value found
    %Sets of if statments to prevent the glider from phasing through the
    %stand.
    if V1 <0 
        V1 = 0;
    end
    if h1 <0 
        h1 = 0;
    end
    if d1 < 0 
        d1 = 0;
    end
    fprintf('In boost rail phase! Height is %d and range is %d \n',h1,d1)
    elseif t(i) <= tb && d1 > dr %Boost flight phase
    alpha1 = alphatrim; %Setting new alpha value
    [q,L,D,M] = aeroPred(alpha1,V1,S,c,alpha,cl0,cd0,cm0); %Grabbing Aero predicitons
    thrust = thrustcurve(t(i)); %Finding thrust at current time
    m = ((tb-t(i))/tb)*(m0-mf)+mf; %Finding mass at current time
    [V1,gamma1,h1,d1] = twoddata(thrust,alpha1,gamma1,V1,D,L,m,g,dt,h1,d1); %Integrating
    theta1 = gamma1 + alpha1; %Finding new theta
    fprintf('In boost flight phase! Height is %d and range is %d \n',h1,d1)
    elseif theta(i) > thetag && t(i) > tb %Transitional phase
    thrust = 0; %No thrust
    m = mf; %Constant mass
    [q,L,D,M] = aeroPred(alpha1,V1,S,c,alpha,cl0,cd0,cm0);%Grabbing Aero prediciton
    [V1,gamma1,h1,d1] = twoddata(thrust,alpha1,gamma1,V1,D,L,m,g,dt,h1,d1);%Integrating
    theta1 = gamma1 + alpha1;%Finding new theta
    fprintf('In transitional phase! Height is %d and range is %d \n',h1,d1)
    else %Glide phase
    theta1 = thetag; %Setting constant theta
    thrust = 0; %No thrust
     m = mf; %Constant mass
    [q,L,D,M] = aeroPred(alpha1,V1,S,c,alpha,cl0,cd0,cm0);%Grabbing Aero prediciton
    [V1,gamma1,h1,d1] = twoddata(thrust,alpha1,gamma1,V1,D,L,m,g,dt,h1,d1);%Integrating
    alpha1 = theta1 - gamma1; %Finding new alpha
    fprintf('In glide phase! Height is %d and range is %d \n',h1,d1)
    end 
    %Storing new values
    V(i+1) = V1; %Velocity
    h(i+1) = distdim(h1,'m','ft'); %Height
    d(i+1) = distdim(d1,'m','ft'); %Distance
    theta(i+1) = radtodeg(theta1); %Pitch angle
    gamma(i+1) = radtodeg(gamma1); %Flight Path angle
    a(i+1) = radtodeg(alpha1); %Angle of attack
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
plot(d,h)
grid on
title('Altittude vs. Downrange Distance')
xlabel('Downrange Distance (ft)')
ylabel('Altittude (ft)')
%Velocity
figure
plot(t,V)
grid on
title('Velociy vs. Time')
ylabel('Velocity (m/s)')
xlabel('Time (s)')
%Angles
%Pitch
figure 
plot(t,gamma,t,theta)
grid on
title('Gamma and theta vs. Time')
ylabel('Gamma and Theta (degrees)')
xlabel('Time (s)')
%Roll
%{
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