import sys
n,k=map(int,input().split())
w=list(map(int,sys.stdin.readlines()))
def f():
 c=t=0
 for j in w:
  t+=j
  if t>m:
   t=j
   c+=1
   if c>k:return 0
 return 1
l,r=max(w),sum(w)
while r-l>=1:
 m=(l+r)//2
 if f():r=m
 else:l=m
print(r)
