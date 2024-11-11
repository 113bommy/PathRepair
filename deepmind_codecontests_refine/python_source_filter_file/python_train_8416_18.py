f=lambda:map(int,input().split())
n,x=f()
t,*l=f()
a=0
for i in l:
  t=min(i,x-t)
  a+=i-t
print(a)