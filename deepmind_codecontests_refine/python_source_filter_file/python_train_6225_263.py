import math
a, b = list(map(int,input().split()))
print(int(a * b / math.gcd(a, b)))