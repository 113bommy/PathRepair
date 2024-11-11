# Python is the best 

def Calc(n, m, k):
    if n + m - 2 < k:
        return -1
    if k <= n - 1:
        return n // (k + 1) * m
    return m / (k - n + 2)


n, m, k = [int(x) for x in input().split()]

print(max(Calc(n, m, k), Calc(m, n, k)))
