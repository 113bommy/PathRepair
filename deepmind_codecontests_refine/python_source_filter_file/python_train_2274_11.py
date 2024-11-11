def gcd(x, y):
    while (y != 0):
        x, y = y, x%y
    return x

n, k = map(int, input().split())
A = list(map(int, input().split()))
g = A[0]
for a in A:
    g = gcd(g, a)
if k < max(A) and k%g == 0:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')