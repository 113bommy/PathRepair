#----Kuzlyaev-Nikita-Codeforces-----
#------------06.04.2020-------------

import math
alph="abcdefghijklmnopqrstuvwxyz"

#-----------------------------------

d,h,v,e=map(int,input().split())
r=v*4/math.pi/d/d
if r<=e:print("NO")
else:
    print("YES")
    print("%.6f"%(h/(r-v)))