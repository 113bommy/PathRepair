N = int(input())
ans = 0
m = INF = 10**9+7
d = []
for i in range(N):
    a, b = map(int, input().split())
    ans += a
    if a > b:
        m = min(m, b)
print(0 if INF == m else ans-m)