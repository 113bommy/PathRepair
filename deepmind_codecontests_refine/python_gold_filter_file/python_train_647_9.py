INF = 1e9
n = int(input())
a = list(map(int, input().split()))
ans = 0
for max_ in range(0, 31):
  curr = 0
  best = 0
  for i in range(n):
    val = -INF
    if(a[i] <= max_): val = a[i]
    curr += val
    best = min(best, curr)
    ans = max(ans, curr - best - max_) 
print(int(ans))