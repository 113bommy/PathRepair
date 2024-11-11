N,M = map(int,input().split())
list = []
for _ in range(n):
  a,b = map(int,input().split())
  list.append([a,b])
list.sort()
ans = 0
for a,b in l:
  ans += min(b,M)*a
  M = max(0,M-b)
print(ans)