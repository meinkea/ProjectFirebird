% Function to determine aerodynamic coefficients
function [CL,CD,CM] = getCoeffs(alpha,a,cl,cd,cm)
% INPUTS:
%   a, cl, cd, & cm are all arrays based on 0 elevator deflection
% OUTPUTS:
%   function outputs lift, drag and moment coefficient based on alpha

% The flyout simulation is assuming no controller. Thus, the coefficients 
% needs to be interpolated based on alpha assuming a constant elevator
% deflection of 0 degrees. Should a controller be added later on,
% interpolatioon will also need to account for elevator deflection.


% 'linear' specifies linear interpolation
% 'extrap' lets the function extrapolate information if your input is
%   outside of the given data range

% Define elevator deflections
%def = [-15,0,15];
CL = interp1(a,cl,alpha,'pchip','extrap');
CD = interp1(a,cd,alpha,'pchip','extrap');
CM = interp1(a,cm,alpha,'pchip','extrap');

%{
CL = interp1(def,CL1,elvDef,'pchip','extrap');
CD = interp1(def,CD1,elvDef,'pchip','extrap');
CM = interp1(def,CM1,elvDef,'pchip','extrap');
%}
end
