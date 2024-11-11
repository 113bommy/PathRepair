r,x1,y1,x2,y2 = map(int,input().split())

import math
if(pow(x2-x1,2)+pow(y2-y1,2) >= r*r):
    	rad = r;
    	print(x1,' ',y1,' ',rad)
else:
    	rad=(r + math.sqrt(pow(x2-x1,2)+pow(y2-y1,2)))/2
    	dist= (math.sqrt(pow(x2-x1,2)+pow(y2-y1,2)))
    	m = rad - dist
    	if dist!=0:
    		x = ((m+dist)*x1 -(m)*x2)/dist
    		y = ((m+dist)*y1 -(m)*y2)/dist
    	else:
    		x = x1+r/2
    		y = y1
    		rad = 0.5*r
    	print(x,' ',y,' ',rad)
    