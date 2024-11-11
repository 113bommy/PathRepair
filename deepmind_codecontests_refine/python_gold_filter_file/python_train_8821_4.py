def pow(n):
    if(n > 0):
        if(n % 2 == 0):
            x = pow(n // 2) % 1000000007
            return (x * x) % 1000000007
        else: return (pow(n - 1) * 2)% 1000000007
    else:
        return 1

n, k = map(int, input().split())
if(n == 0): print(0)
else: print((pow(k) * (2 * n - 1) + 1) % 1000000007)
