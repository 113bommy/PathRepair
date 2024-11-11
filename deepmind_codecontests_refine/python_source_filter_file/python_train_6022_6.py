import bisect
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
a.sort()
b.sort()
c.sort()
ans=0
for i in range(n):
  x=b[i]
  y=bisect.bisect_left(a,x)
  z=bisect.bisect_right(c,x)
    ans+=(n-z)*y
print(ans)