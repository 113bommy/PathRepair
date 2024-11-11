f=lambda:map(int,input().split())
input()
p,*A=f()
B=f()
s=0
for a,b in zip(A,B):
  t=min(b,a+p)
  p=a-max(0,t-b)
  s+=t
print(s)