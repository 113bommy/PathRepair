x,y,z,t1,t2,t3=map(int,input().split())
a=abs(y-x)*t1
b=abs(x-z)*t2+t3*2+abs(y-x)*t2+t3
if b<a:
    print("YES")
else:
    print('NO')