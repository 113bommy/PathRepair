import math
a, b = map(int,input().split())
ans = (a * b) / math.gcd(a,b)
print(int(ans))