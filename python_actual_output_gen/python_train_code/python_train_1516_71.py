x,y,z,t1,t2,t3=map(int,input().split())
p=abs(x-y)*t1
q=(abs(z-x)*t2)+3*t3+(abs(x-y)*t2)
if p>q:
    print("YES")
else:
    print("NO")