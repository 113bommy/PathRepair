n = int(input())

ans = [0] * (n + 1)
ai = 1

prime = [True] * (n + 1)
p = 2
while p <= n:
    if prime[p]:
        for i in range(p, n + 1, p):
            prime[i] = False
            ans[i] = ai
        ai += 1
    p += 1

print(' '.join(map(str, ans[2:])))
