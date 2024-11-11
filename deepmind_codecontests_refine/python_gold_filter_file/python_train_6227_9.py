N,M = map(int,input().split())
list = []
for _ in range(N):
  a,b = map(int,input().split())
  list.append([a,b])
list.sort()
ans = 0
for a,b in list:
  ans += min(b,M)*a
  M = max(0,M-b)
print(ans)