function [val] = orient_GS(p,q,r)
global XY_GS
    val = ((XY_GS(q,2) - XY_GS(p,2)) * (XY_GS(r,1) - XY_GS(q,1))) - ((XY_GS(q,1) - XY_GS(p,1)) * (XY_GS(r,2) - XY_GS(q,2)));
    if (val == 0) 
        return;  
    end
    if (val>0)
        val=1;
    else
        val=2;
    end
end