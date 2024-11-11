n = int(input())
result = []
k = 1
while k*k <= n:
    if n%k == 0:
        result.append(int(n*(k-1)//2 + k))
        if k*k != n:
            result.append(int(n*(n/k-1)//2 + n//k))
    k += 1
result = sorted(result)
print(*result)
