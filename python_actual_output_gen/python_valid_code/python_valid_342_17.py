N, C, K = map(int, input().split())
T = sorted([int(input()) for _ in range(N)])
s, c = 0, C
ans = 1
for t in T:
    if t <= s + K and c:
        c -= 1
    else:
        s = t
        c = C
        ans += 1
print(ans)