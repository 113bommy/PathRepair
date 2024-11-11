N = int(input())
s = [input() for i in range(N)]
M = int(input())
t = [input() for i in range(M)]

ans = 0
for i in a:
  ans = max(ans, s.count(i) - t.count(i))

print(ans)