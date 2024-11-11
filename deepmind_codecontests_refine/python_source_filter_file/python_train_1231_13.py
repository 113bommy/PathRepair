N, H = map(int, input().split())
bs = []
maxA = 0
ans = 0
for _ in range(N):
    a, b = map(int, input().split())
    maxA = max(maxA, a)
    bs.append(b)
bs.sort(reverse=True)

for b in bs:
    if H < 0: break
    if b > maxA:
        H -= b
        ans += 1

if H > 0:
    ans += (-(-H//maxA))
print(ans)
