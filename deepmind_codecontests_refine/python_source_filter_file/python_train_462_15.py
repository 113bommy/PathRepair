import math
l=list(map(int,input().split()))
d=((l[4]-l[2])**2 +(l[3]-l[1])**2)**0.5
#print(d)
print(d)
m=(d/l[0]/2)
#print(m)
m=math.ceil(m)
#m=int(m)
print(int(m))
