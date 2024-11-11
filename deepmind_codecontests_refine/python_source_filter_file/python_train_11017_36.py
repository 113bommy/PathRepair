N = int(input())
A = list(map(int, input().split()))

mx = max(A)
mn = min(A)

ans = []
if abs(mx) > abs(mn):
    for i in range(1, N+1):
        ans += [[A.index(mx)+1, i]]
    for i in range(1, N):
        ans += [[i, i+1]]
else:
    for i in range(1, N+1):
        ans += [[A.index(mn)+1, i]]
    for i in range(N, 0, -1):
        ans += [[i, i-1]]

print(len(ans))
for x, y in ans:
    print(x, y)