a,v=map(int,input().split())
b,w=map(int,input().split())
t=int(input())

d=abs(a-b)


if(v*t>=b*t+d): print("YES")
else:print("NO");
