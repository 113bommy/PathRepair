f=lambda:map(int,input().split())
n,x=f()
l=f()
t=a=0
for i in l:
  t=min(i,x-t)
  a+=i-t
print(a)