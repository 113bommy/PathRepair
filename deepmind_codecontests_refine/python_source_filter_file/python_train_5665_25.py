import math
n=int(input())
u=0
l=0
d=0
for i in range(n):
    x, y=map(int,input().split())
    u+=x
    l+=x
    xs=x%2
    ys=y%2
    if xs!=ys:
        d=1

if u%2!=0 and l%2!=0:
   if d==1:
      print(1)
   else:
      print(-1)
elif u%2==0 and l%2==0:
   print(0)
else:
   print(1)                                  
                


