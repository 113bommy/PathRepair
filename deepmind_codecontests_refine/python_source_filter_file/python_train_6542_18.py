N, P = map(int, input().split())
A = list(map(int, input().split()))

odd = 0
for a in A:
    if a % 2 != 0:
        odd += 1

if odd == 0
    if P == 1:
        res = 0
    else:
        res = 2 ** N
else:
    res = 2 ** (N - 1)

print(res)