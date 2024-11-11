n, k = map(int, input().split())
x = list(map(int, input().split()))

ans = 10**8*2

for i in range(n-k+1):
    l, r = x[i], x[i+k-1]
    ans = min(ans, min(abs(l), abs(r)) + abs(l - r))

print(ans)
