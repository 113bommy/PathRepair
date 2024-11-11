r,p=range,print
n,a,b=map(int,input().split())
if a+b>n+1or a*b<n:exit(p(-1))
l=[[]for i in r(b-1)]+[list(r(1,a+1))]
for i in r(a+1,n+1):l[-(i-a-1)%(b-1)-2].append(i)
for i in l:p(*i,end=" ")