n,m=map(int,input().split())
a=0
b=n%2
n=n-b
for i in range(n//2,n):
   if a==0:
      if i%m==0:
         print(i+b)
         a=1
if a==0:print(-1)