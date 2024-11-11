def diplomas(n, k):
    return ((n // 2) // (k + 1)), ((n // 2) // (k + 1)) * k, n - ((n // 2) // (k + 1)) - ((n // 2) // (k + 1)) * k


N, K = [int(i) for i in input().split()]
print(diplomas(N, K))
