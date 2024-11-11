import sys
n=int(input())
l=list(map(int,input().split()))
l.sort()
g=(l[n-1]-l[0])
t=1
for i in range(1,n):
   if (l[i]-l[i-1])==g or (l[i]-l[i-1])==0:
       continue
   elif (l[i]-l[i-1])==g//2:
       t=2
       continue
   else:
       print(-1)
       sys.exit()
if g%2==0:
    print(g//2)
else:
    print(g)
       