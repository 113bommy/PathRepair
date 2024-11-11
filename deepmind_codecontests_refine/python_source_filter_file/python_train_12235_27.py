n = int(input())
u = ((4 * 3 * (2**(n-3))) << 1)
if n > 3:
    u +=(n-3) * 9 * (2**(n-4))
print(u)
