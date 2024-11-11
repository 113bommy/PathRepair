a,b,h,m = map(int, input().split())

import math
(a**2+b**2-2*a*b*math.cos(math.radians((360*h/12+30*m/60)-360*m/60)))**(1/2)