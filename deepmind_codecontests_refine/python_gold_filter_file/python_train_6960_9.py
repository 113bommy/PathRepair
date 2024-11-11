W,H,N=map(int,input().split())
a,b,c,d=0,W,0,H

for i in range(N):
  x,y,A=map(int,input().split())
  if A==1:
    a=max(a,x)
  if A==2:
    b=min(b,x)
  if A==3:
    c=max(c,y)
  if A==4:
    d=min(d,y)
  
print(max(0,b-a)*max(0,d-c))