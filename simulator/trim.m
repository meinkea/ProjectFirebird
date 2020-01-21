function [ alphatrimmed ] = trim( elevator,alpha,cm)
% Summury: Finds the trimmed alpha for each elevator angle

elevator_limits = [-15,0,15];
%Finding alpha where cm=0 at each limit
cmzero_up = interp1(cm(:,1),alpha,0,'pchip','extrap');
cmzero_neutral = interp1(cm(:,2),alpha,0,'pchip','extrap');
cmzero_down = interp1(cm(:,3),alpha,0,'pchip','extrap');
%Storing those values
alphatrim = [cmzero_up, cmzero_neutral, cmzero_down];
%Outputing trimmed conditons
alphatrimmed = interp1(elevator_limits,alphatrim,elevator,'pchip','extrap');
end
