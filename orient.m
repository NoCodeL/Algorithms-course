function [val] = orient(p,q,r)
global XY
    val = ((XY(q,2) - XY(p,2)) * (XY(r,1) - XY(q,1))) - ((XY(q,1) - XY(p,1)) * (XY(r,2) - XY(q,2)));
    if (val == 0) 
        return;  
    end
    if (val>0)
        val=1;
    else
        val=2;
    end
end