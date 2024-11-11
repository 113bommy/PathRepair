def is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


def primes_upto(M):
    p = [2]
    i = 3
    while p[-1] < M:
        if is_prime(i):
            p.append(i)
        i += 2
    return p[:-1]


n, k = [int(x) for x in input().split(' ')]

P = primes_upto(n)

cnt = 0
for i in range(len(P) - 1):
    if P[i] + P[i + 1] + 1 in P:
        cnt += 1
if cnt >= k:
    ans = 'YES'
else:
    ans = 'NO'
print(ans)
