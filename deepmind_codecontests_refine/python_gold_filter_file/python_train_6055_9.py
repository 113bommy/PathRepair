n=int(input())
l=list(map(int,input().split(" ")))
s=0
for i in l :
   s+=(i&1)
if s==0 or s==n:
    print(*l)
else :
    l.sort()
    print(*l)
   