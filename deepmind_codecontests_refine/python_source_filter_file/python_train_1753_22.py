import sys
import math
K, A, B = list(map(int, input().split()))

if (A >= K):
    print(1)
    sys.exit()
elif (A - B) <= 0:
    print(-1)
    sys.exit()
d = A - B

p = K-A
q = p/d
if ((p % d) != 0):
    q += 1
print(int(2*q + 1))