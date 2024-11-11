x,y,z,t1,t2,t3=map(int,input().split())
s=abs(x-y)*t1
d=abs(z-x)*t2+abs(x-y)*t2+3
if(s>=d):
  print("YES")
else:
  print("NO")
