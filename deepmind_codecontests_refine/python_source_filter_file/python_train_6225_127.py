import math
A, B = map(int, input().split())
ans = int((A*B)/math.gcd(A,B))
print(ans)