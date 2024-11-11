x,y,z,t1,t2,t3=list(map(int,input().split()))
p=abs(y-x)*t1
q = abs(z-x)*t2 + 4*t3 + abs(y-x)*t2

if q < p:
    print('YES')
else:
    print('NO')
