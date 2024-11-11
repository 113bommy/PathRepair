N, P = map(int, input().split())

S = input()

ans = 0
if P == 2 or P == 5:
    for i, s in enumerate(S):
        if int(s) % P == 0:
            ans += i + 1
else:
    counts = [0] * P
    h = 0
    d = 1
    for s in reversed(S):
        m = int(s) * d % P
        h = (h + m) % P
        counts[h] += 1
        d = (d * 10) % P
        ans = counts[0]
    for i in counts:
        ans += (i*(i-1))//2

print(ans)
