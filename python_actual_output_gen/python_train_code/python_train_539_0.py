def pr(x):
    d = 2
    while d * d <= x:
        if x % d == 0:
            return 0
        d += 1
    return 1

def cnt(n, k):
    if not pr(n) or n < k: return 0
    n1 = n // k
    return n1 - sum(cnt(n1, i) for i in range(2, min(k, n1 + 1)))
    
a, b, k = map(int, input().split())
ans = cnt(b, k) - cnt(a - 1, k)
print(ans)
