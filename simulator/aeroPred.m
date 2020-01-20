function [q,L,D,M] = aeroPred(alpha,velocity,S,c,a_array,cl_array,cd_array,cm_array)
% INPUTS:
%   Alpha               (degrees)
%   Velocity            (m/s)
%   S (Planform Area)   (m^2)
%   c (chord length)    (m)
%   a_array: array containing alpha increments of aero data
%   cl_array: array containing Cl values at various alpha's. Only data for
%       0 degree elevator deflection
%   cd_array: array containing Cd values at various alpha's. Only data for
%       0 degree elevator deflection
%   cm_array: array containing Cm values at various alpha's. Only data for
%       0 degree elevator deflection
% OUTPUTS:
%   Dynamic Pressure (Pa)
%   Lift             (N)
%   Drag             (N)

% Assuming constant density
rho = 1.225; % kg/m^3

% Calculate dynamic pressure
q = .5*rho*(velocity.^2); % Pascals

% Call function to get aerodynamic coefficients
[Cl,Cd,Cm] = getCoeffs(alpha,a_array,cl_array,cd_array,cm_array);

% Calculate lift, drag, and moment
L = q*S*Cl;
D = q*S*Cd;
M = q*S*c*Cm;
end