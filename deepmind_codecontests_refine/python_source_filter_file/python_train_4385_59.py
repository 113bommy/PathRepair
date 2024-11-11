x,y,z,t1,t2,t3=map(int,input().split())
p=abs(x-y)*t1
q=abs(x-z)*t2+abs(x-y)*t2+3
if q<p:
    print("YES")
else:
    print("NO")