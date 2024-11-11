n = int(input())

sieve = [0] * (n + 1)

for x in range(2, n + 1):
    if sieve[x]: continue
    for u in range(2*x, n + 1, x):
        sieve[u] = x

ans = set()

def solve(k):
    ans.add(k)
    if sieve[k] == 0:
        ans.add(1)
    else:
        solve(k//sieve[k])


solve(n)
print(*sorted(ans, reverse=True))
