N, K = map(int, input().split())
A = list(map(int, input().split()))
import fractions
import functools
gcd = functools.reduce(fractions.gcd, A)
A_max = max(A)
if (A_max >= K and K % gcd == 0):
    print('POSSEBLE')
else:
    print('IMPOSSIBLE')