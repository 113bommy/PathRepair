n = int(input())
ans = 0
for i in range(n):
  l,r = map(int,input().split())
  ans += r+1-l
print(ans)