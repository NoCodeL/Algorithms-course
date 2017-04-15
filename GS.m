function [GShull] = GS()
global XY N XY_GS
p0 = find(XY==min(XY(:,2)))-N;
XY_GS = circshift (XY, N-p0+1);
theta = zeros(N,1);
for i=2:N
    theta(i) = atand((XY_GS(i,2) - XY_GS(1,2))/( XY_GS(i,1) - XY_GS(1,1)));
    if (XY_GS(i,1) < XY_GS(1,1))
        theta(i) = theta(i)+180;
    end
end
XY_GS = [XY_GS,theta];
XY_GS = sortrows(XY_GS,3);
XY_GS(:,3) = [];
GShull = [1,2,3];
for i=4:N
    while(orient_GS(GShull(end)-1,GShull(end), i)~=2)
        GShull = GShull(1:end-1);
    end
    GShull(end+1)=i;
end
    GShull(end+1)=1;
end