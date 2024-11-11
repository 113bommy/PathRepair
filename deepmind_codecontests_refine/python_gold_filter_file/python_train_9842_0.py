from math import pi
d,h,v,e=map(int,input().split())
v=v/(pi*((d/2)**2))
d=h/(v-e)
if v-e>0 and d<=10000:
    print('YES')
    print(d)
else:
    print('NO')