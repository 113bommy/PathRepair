n=int(input())
m=list(map(int,input().split()))
ans=1

for i in range(1,n):
  if max(m[:i]) <= m[i]:
    ans += 1
print(ans)