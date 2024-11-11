n,x,t=map(int,input().split())
s=n//x
if n%x!=0:
  s+=1
print(t*s)