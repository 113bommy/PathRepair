from itertools import accumulate

N, K, *A = map(int, open(0).read().split())

s = sum(A)
divisor = []
for i in range(1, int(s ** 0.5) + 1):
    if s % i == 0:
        divisor.append(i)
        if i != s // i:
            divisor.append(s // i)

ans = 0
for d in divisor:
    x = sorted(v % d for v in A)
    y = [d - r for r in x]
    x_s = [0] + list(accumulate(x))
    y_s = list(accumulate(y[::-1]))[::-1] + [0]

    for i in range(N + 1):
        if x_s[i] <= K and x_s[i] == y_s[i]:
            ans = max(ans, d)
            break

print(ans)
