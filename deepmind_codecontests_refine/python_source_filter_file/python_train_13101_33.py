N, C, K = map(int,input().split())
T = [int(input()) for k in range(N)]
T = sorted(T)

p = C-1
d = T[0]
ans = 1
for t in T[1:]:
    if p == 0 or t > d:
        d = t+K
        p = C-1
        ans += 1
    else:
        p -= 1

print(ans)