n = int(input())
ppp = list(map(int, (input() for _ in range(n))))

tmp = [0] * (n + 1)
for p in ppp:
    tmp[p] = tmp[p - 1] + 1

print(n - max(tmp))
