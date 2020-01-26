%main
%Version 5 of Orange Team Flyout Sim
%Contributors:
%William "Mikhaila" Gregory
%Christopher Opificius

%Cleaning up all previous info for new run
clc;
clear;
close all;

%Defining constants
load('aeroData.mat'); %Aerodynamic data

thetag = -8; %degrees (pitch angle for glide phase)
alphaboost = -2.25; %degrees(the alpha value for cl=0)

m0 = 0.167; %kg (inital mass)
mf = m0-0.0104; %kg (final mass)
tb = 0.840; %seconds (burn time)
drail = distdim(3,'ft','m'); %meters
dt = 0.001; %time interval

%Setting initial conditions
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
Thrust(1) = 0; %thrust in newtons

%Setting constant values
i = 1;
hr = drail*sind(theta(1)); %rail height in meters
dr = drail*cosd(theta(1)); %rail distance in meters
%Preventing code from back tracking to other phases
OnRail = true;
BoostFlight = true;
Transition = true;
Glide = false;
%Simulation
while h(i) >= -0.0000000000001
    
    %Boost Rail Phase
    if h(i) < hr && d(i) < dr && t(i) < tb && OnRail == true
        
        theta(i) = theta(1); %Locking in theta
        gamma(i) = gamma(1); %Overwriting the gamma value found
        a(i) = a(1); %Locking in alpha
        
        %Sets of if statments to prevent the glider from phasing through the
        %stand.
        %Resetting velocity
        if V(i) < 0
            V(i) = 0;
        end
        %Resetting height
        if h(i) < 0
            h(i) = 0;
        end
        %Resetting distance
        if d(i) < 0
            d(i) = 0;
        end
        
        thrust = thrustcurve(t(i)); %Finding thrust at current time
        m = ((tb-t(i))/tb)*(m0-mf)+mf; %Finding mass at current time
        
        %Switching to Boost flight phase when this is true.     
        fprintf('In boost rail phase! Gamma is %d and Alpha is %d \n',gamma(i),a(i))
        
        %Boost flight phase
    elseif t(i) <= tb && d(i) > dr && h(i) > hr && BoostFlight == true
        OnRail = false; %Rail can no longer be used
        
        %Defining angles
        a(i) = alphaboost; %Setting new alpha
        theta(i) = gamma(i) + a(i); %Finding new theta
        
        thrust = thrustcurve(t(i)); %Finding thrust at current time
        m = ((tb-t(i))/tb)*(m0-mf)+mf; %Finding mass at current time

        fprintf('In boost flight phase! Gamma is %d and Alpha is %d \n',gamma(i),a(i))
        
        %Transitional phase
    elseif theta(i) >= thetag && t(i) > tb && Transition == true
        BoostFlight = false;
        
        thrust = 0; %No thrust
        m = mf; %Constant mass
        
        %Define angles
        a(i) = alphaboost; %Setting new alpha
        theta(i) = gamma(i) + a(i);%Finding new theta
        
        %Transitioning to glide phase when this is true.
        if theta(i) <= thetag
            Transition = false;
            Glide = true;
        end

        fprintf('In transitional phase! Gamma is %d and Alpha is %d \n',gamma(i),a(i))
        
        %Glide phase
    elseif Glide == true
        Transition = false;
        
        theta(i) = thetag; %Setting constant theta
        thrust = 0; %No thrust
        m = mf; %Constant mass
        a(i) = theta(i) - gamma(i); %Finding new alpha

        fprintf('In glide phase! Gamma is %d and Alpha is %d \n',gamma(i),a(i))
    end
    
    
    [q,L,D,M] = aeroPred(a(i),V(i),S,c,alpha,cl0,cd0,cm0); %Grabbing Aero predicitons
    [Vel,path,alt,down] = twoddata(thrust,a(i),gamma(i),V(i),D,L,m,g,dt,h(i),d(i),Glide); %Integrating
    
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
    Thrust(i+1) = thrust; %Thrust

    %Propigate
    t(i+1) = t(i) + dt;
    i = i+1;
    
    %Ending the simulation if glider goes past start point.
    if d(i) < 0
        break;
    end
end

fprintf('Simulation complee! Generating plots... \n');

%2D Flight Path
subplot(2,2,1)
plot(d*3.28084,h*3.28084,'LineWidth',2)
grid on
title('Altittude vs. Downrange Distance')
xlabel('Downrange Distance (ft)')
ylabel('Altittude (ft)')

%Velocity
subplot(2,2,2)
plot(t,V*3.28084,'LineWidth',2)
grid on
title('Velocity vs. Time')
ylabel('Velocity (ft/s)')
xlabel('Time (s)')

%Angles
%Pitch and Flight Path
subplot(2,2,3)
plot(t,gamma,t,theta,'LineWidth',2)
grid on
legend('Flight Path Angle','Pitch Angle')
title('Flight Path Angle and Pitch Angle vs. Time')
ylabel('Angle (degrees)')
xlabel('Time (s)')

%Angle of Attack
subplot(2,2,4)
plot(t,a,'LineWidth',2)
grid on
title('Angle of Attack vs. Time')
ylabel('Angle of Attack (degrees)')
xlabel('Time (s)')

fprintf('Plots generated! Ending program...')
