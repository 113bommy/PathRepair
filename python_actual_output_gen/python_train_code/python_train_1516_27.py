x,y,z,t1,t2,t3=map(int,input().split())
if((abs(z-x)*t2+2*t2+abs(y-x)*t2+t3)>abs(x-y)*t1):
    print('NO')
else:
    print('YES')