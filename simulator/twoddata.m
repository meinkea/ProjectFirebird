function [velocity,gamma,height,downrange] = twoddata(thrust,alpha,gamma,velocity,drag,lift,mass,gravity,dtime,height,downrange)
%Summary of this function: Does Euler's Method to integrate
%   Detailed explanation goes here
veldot = (thrust*cos(alpha)-drag-mass*gravity*sin(gamma))/mass;%acceleration of glider
gamdot = (thrust*sin(alpha)+lift-mass*gravity*cos(gamma))/(mass*velocity); %pitch rate of glider
downdot = velocity*cos(gamma); %horizontal velocity of glider
heightdot = velocity*sin(gamma); %vertical velocity of glider
%time step and output
velocity = velocity + veldot*dtime;
gamma = gamma + gamdot*dtime;
height = height + heightdot*dtime;
downrange = downrange + downdot*dtime;

end


