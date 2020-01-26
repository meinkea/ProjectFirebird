function [velocity1,gamma1,height1,downrange1] = twoddata(thrust,alpha,gamma,velocity,drag,lift,mass,gravity,dtime,height,downrange,Glide)
%Summary of this function: Does Euler's Method to integrate
%   The first if statement is for when the glide is in flight. Its assumed
%   that there is no lift being generated simply because its been trimmed
%   out to do so. 
%The second portion is for when the glider is in gliding flight.

if Glide == false
veldot = ((thrust*cosd(alpha)-drag)/mass)-(gravity*sind(gamma)); %acceleration of glider
gamdot = -((gravity/velocity)*cosd(gamma)); %pitch rate of glider
downdot = velocity*cosd(gamma); %horizontal velocity of glider
heightdot = velocity*sind(gamma); %vertical velocity of glider    
end

veldot = ((thrust*cosd(alpha)-drag)/mass)-(gravity*sind(gamma)); %acceleration of glider
gamdot = ((thrust*sind(alpha)+lift)/(mass*velocity))-((gravity/velocity)*cosd(gamma)); %pitch rate of glider
downdot = velocity*cosd(gamma); %horizontal velocity of glider
heightdot = velocity*sind(gamma); %vertical velocity of glider

%time step and output
velocity1 = abs(velocity + veldot*dtime);
gamma1 = gamma + radtodeg(gamdot)*dtime; %radtodeg is needed or else code breaks
height1 = height + heightdot*dtime;
downrange1 = downrange + downdot*dtime;
end
