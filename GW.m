function [GWhull] = GW()
global XY N
    p = find(XY==min(XY(:,1)));
left = p;
GWhull=p;
do=1;
while (p ~= left || do ==1)
    do=2;
    q = mod((p+1),N);
    for i=1:N
        [val]=orient(p,i,q);
        if val==2
            q=i;
        end
    end
    p=q;
    GWhull(end+1)= q;        
end
end