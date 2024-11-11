M = int(input())
DC = [tuple(map(int, input().split())) for _ in range(M)]

D = 0
C = 0
for d, c in DC:
    D += d * c
    C += c

ans = C - 1
ans += (D - 1) // 9
print(ans)
