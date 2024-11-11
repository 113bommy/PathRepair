n,a = list(map(int,input().split())) #1e5; 180
sa  = 360/n
v2  = 1
v1  = 2
vd  = max(1,int(a*n/180+0.5))   #round
v3  = max(n,v1+vd)      #may not allowed
print(v1,v2,v3)

