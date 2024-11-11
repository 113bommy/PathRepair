N, M = map(int,input().split())
l = 0; r = N;
for i in range(M):
  a, b = map(int,input().split())
  l = max(l, a)
  r = min(r, b)
print(max(0, abs(r-l)+1))