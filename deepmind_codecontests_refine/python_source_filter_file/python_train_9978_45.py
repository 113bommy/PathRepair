from collections import Counter

mod = 10**9 + 7

def init(n):
    # 階乗とその逆元をグローバルに定義
    global factorial, inverse
    # 0-indexedでそれぞれ１で初期化
    factorial = [1]*(n+1)
    inverse = [1]*(n+1)

    fact = 1
    for p in range(1,n+1):
        fact *= p
        fact %= mod
        factorial[p] = fact

    inv = pow(fact, mod-2, mod)
    inverse[n] = inv
    for p in range(2,n+1)[::-1]:
        inv *= p
        inv %= mod
        inverse[p-1] = inv

def comb(n,r):
    if n < r:
        return 0
    return factorial[n] * inverse[n-r] * inverse[r] % mod

n = int(input())
a = list(map(int,input().split()))

b = Counter(a).most_common()[0][0]
pos = []
for i, ai in enumerate(a):
    if ai == b:
        pos.append(i)

l, r = pos
L, R = l, n-r

init(n+1)

for k in range(1, n+2):
    ans = comb(n+1, k) - comb(L+R, k-1)
    print(ans)