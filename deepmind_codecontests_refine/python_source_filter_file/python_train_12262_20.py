import math
K = int(input())
res = sum([math.gcd(math.gcd(a, 1), c) for a in range(1,K+1) for b in range(1,K+1) for c in range(1,K+1)])
print(res)