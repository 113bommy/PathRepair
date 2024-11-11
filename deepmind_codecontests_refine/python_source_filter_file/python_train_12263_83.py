import math
n = int(input())
a = math.ceil(n/1.08)
b = math.floor((n+1)/1.08)
print(a*(a == b) or ":(")