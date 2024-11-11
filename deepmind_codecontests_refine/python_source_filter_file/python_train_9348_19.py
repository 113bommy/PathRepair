#ABC132 D
import math
def cmb(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))
N, K = map(int, input().split())
for i in range(K):
    try:
        print((cmb(N - K + 1, i + 1) * cmb(K, i)) % ((10 ** 9) + 7))
    except:
        print(0)