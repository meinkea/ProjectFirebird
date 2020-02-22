%main
%Version 6.2 of Orange Team Flyout Sim
%Contributors:
%William "Mikhaila" Gregory
%Christopher Opificius
clc;
clear;
close all;
%Setting up Aerodata
StayHere = 0;
RunProgram = 'y';
Loop = 1;
while StayHere == 0 
NewAero = input('Do you want to generate a new matlab aerodata file? [y,n] | ','s'); %Asking for input
if NewAero == 'y' %if they want to generate a new file
ExcelName = input('What is the Excel file name? (include the .xlsx) | ','s');%asking for name of excel file
fprintf('Please wait while the aerodata is created. \n')
RawAero = table2array(readtable(ExcelName)); %getting excel info
alpha = unique(RawAero(:,1)); %Alphas being set
elevator = unique(RawAero(:,2)); %elevator being set
cl = reshape(RawAero(:,3),length(alpha),length(elevator)); %cl being set
cd = reshape(RawAero(:,4),length(alpha),length(elevator)); %cd being set
cm = reshape(RawAero(:,5),length(alpha),length(elevator)); %cm being set
S = RawAero(1,6); %defining span
c = RawAero(1,7); %defining cord
clear CL
clear CD
clear Cm
fprintf('Please input a file name to save as. \n')
FileName = input('Only special character can be an underscore. | ','s'); %Saving the file
%Removing unnessesary files
clear StayHere
clear NewAero
save(FileName);
StayHere = 1;
elseif NewAero == 'n' %if they want to load in aerodata
fprintf('Please input file name of aerodata to load. \n')
FileName = input('Only special character can be an underscore. | ','s');
StayHere = 1;
else %if they're bad at following instructions
fprintf('Thats not a valid option. Please enter y or n with no spaces.\n')
end
end
%end of aero input phase
%start of simulation loop
while RunProgram == 'y'
%constants
clearvars -except FileName Loop
load(FileName);
load('Thrust'); %Aerodynamic data
elevator_setting = input('In degrees, set the elevator deflection. | '); %Setting the elevator angle
thetag = input('In degrees, set the glide pitch angle.(Make it negative) | '); %degrees (pitch angle for glide phase)
alphaboost = 0; %degrees(the alpha value for trimmed conditions)
m0 = input('In kilograms, set the initial mass of the glider. (with propellant) | ');
mf = m0-0.0104; %kg (final mass)
tb = 0.840; %seconds (burn time)
g = 9.80655; %meters per second (gravity)
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
GlideRatio(1)=0;
hr = drail*sind(theta(1)); %rail height in meters
dr = drail*cosd(theta(1)); %rail distance in meters
%Preventing code from back tracking to other phases
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
        Percentage = (t(i)/tb)*100;
        fprintf('In boost rail phase! %2f of boost complete.\n',Percentage)
        
        %Boost flight phase
    elseif t(i) <= tb && d(i) > dr && h(i) > hr && BoostFlight == true
        OnRail = false; %Rail can no longer be used
        
        %Defining angles
        a(i) = alphaboost; %Setting new alpha
        theta(i) = gamma(i) + a(i); %Finding new theta
        
        thrust = thrustcurve(t(i)); %Finding thrust at current time
        m = ((tb-t(i))/tb)*(m0-mf)+mf; %Finding mass at current time
        Percentage = (t(i)/tb)*100;
        fprintf('In boost flight phase! %2f complete.\n',Percentage)
        
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
            hglide = h(i);
        end
        Dif = theta(i) - thetag;
        fprintf('In transitional phase! %2f off from glide.\n', Dif)
        
        %Glide phase
    elseif Glide == true
        Transition = false;
        elevator_setting = 0;
        theta(i) = thetag; %Setting constant theta
        thrust = 0; %No thrust
        m = mf; %Constant mass
        a(i) = theta(i) - gamma(i); %Finding new alpha
        
        fprintf('In glide phase! %2f from the ground.\n', h(i))
    end
    
    
    [q,L,D,M] = aeroPredic(a(i),V(i),S,c,alpha,cl,cd,cm,elevator_setting); %Grabbing Aero predicitons
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
    GlideRatio(i+1) = L/D;

    %Propigate
    t(i+1) = t(i) + dt;
    i = i+1;
    
    %Ending the simulation if glider goes past start point.
    if d(i) < 0
        fprintf('Glider went past starting point! Ending Simulation...\n')
        break;
    end
end
fprintf('Simulation complete! Generating plots... \n');

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

fprintf('Plots generated! \n')
impact = abs(((V(length(t)).^2)*m0)*sind(gamma(length(t))));
%nose cone is 50mm
MaxV = max(V);
MaxD = max(d);
MaxH = max(h);
GlideV = V(length(t));
ellapsedT = t(length(t));
fprintf('Impact energy is %4f J. \n',impact)
fprintf('Max velocity is %4f m/s and glide velocity is %4f m/s. \n',MaxV,GlideV)
fprintf('Max altitude is  %4f m and max distance is %4f m. \n',MaxH,MaxD)
fprintf('Total flight time is %4f s. \n',ellapsedT)
fprintf('\n Would you like to run another simulation at a different deflection and or glide slope? \n')
RunProgram = input('[y,n] Output will be saved. | ','s');
if RunProgram == 'y'
    OutputFile = sprintf('Run%u',Loop);
    save(OutputFile);
    Loop = Loop + 1;
    fprintf('Run %u beginning...\n')
else
    OutputFile = sprintf('Run%u',Loop);
    save(OutputFile);
end
end
fprintf('\n')
fprintf('All runs have been saved. PLEASE NOTE THE FOLLOWING:\n')
fprintf('Rerunning the program will overwrite the saved Output files.\n')
fprintf('Rename files you wish not to overwrite.\n')
fprintf('Ending program...')
