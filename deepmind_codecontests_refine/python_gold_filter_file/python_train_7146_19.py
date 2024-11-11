R,x,y,u,v=map(int,input().split())
d=((u-x)**2+(v-y)**2)**.5
r=(R+d)/2
if d>R:
 print(x,y,R)
elif d:
 k=(R-d)/2/d
 print(x+(x-u)*k,y+(y-v)*k,r)
else:print(x+r,y,r)