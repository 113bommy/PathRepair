#Bhargey Mehta (Junior)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 998244353
sys.setrecursionlimit(1000000)

def solve(n, d, p):
    a = 0
    while n > 0:
        a += (n%10)*pow(10, p, MOD)
        if d > 0:
            p += 2
            d -= 1
        else:
            p += 1
        n = n//10
        a = a % MOD
    return a

n = int(input())
a = list(map(int, input().split()))
d = {i: 0 for i in range(1, 11)}
for ai in a:
    d[len(str(ai))] += 1

ans = 0
for ai in a:
    for di in d:
        ans += (d[di] * solve(ai, di, 0)) % MOD
        ans += (d[di] * solve(ai, di, 1)) % MOD
        ans = ans % MOD
print(ans)