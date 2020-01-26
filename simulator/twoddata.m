function [velocity1,gamma1,height1,downrange1] = twoddata(thrust,alpha,gamma,velocity,drag,lift,mass,gravity,dtime,height,downrange)
%Summary of this function: Does Euler's Method to integrate
%   Detailed explanation goes here
veldot = ((thrust*cosd(alpha)-drag)/mass)-(gravity*sind(gamma)); %acceleration of glider
gamdot = ((thrust*sind(alpha)+lift)/(velocity*mass))-((gravity/velocity)*cosd(gamma)); %pitch rate of glider
downdot = velocity*cosd(gamma); %horizontal velocity of glider
heightdot = velocity*sind(gamma); %vertical velocity of glider
%time step and output
velocity1 = abs(velocity + veldot*dtime);
gamma1 = gamma + gamdot*dtime;
height1 = height + heightdot*dtime;
downrange1 = downrange + downdot*dtime;
end
