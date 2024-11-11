n, m, k = map(int, input().split())
if (n * m * 2) % k != 0:
    print("NO")
    exit()
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a
div = 0
if k % 2 == 0:
    k //= 2
    div = 1
g = gcd(n, k)
a = n // g
b = (m * g) // k
if div == 1:
    if 2 * a <= n:
        a *= 2
    else:
        b *= 2
print("YES")
print(a, 0)
print(0, b)
print(0, 0)
