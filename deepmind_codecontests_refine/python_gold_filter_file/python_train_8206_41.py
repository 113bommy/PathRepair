n=int(input())
m=list(map(int,input().split()))
a=sum(m)
for i in range(1,n):
  m[i]+=m[i-1]
ans=99999999999999
for i in m[:n-1]:
  ans=min(ans,abs(a-i-i))
print(ans)