def gcd(a, b):
    if b == 0:
        return a
    a = a % b
    a, b = b, a
    return gcd(a, b)

n, k = map(int, input().split())
ans = n * (10 ** k) / gcd(n, 10 ** k)
print(ans)