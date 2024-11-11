t,s,x=map(int,input().split())
if (x-t)>=0:
    z=(x-t)%s
else:
    z=1
if  (x-t)>1:
    z1=(x-t-1)%s
else:
    z1=1
if z==0 or z1==0:
    print('YES')
else:
    print('NO')
