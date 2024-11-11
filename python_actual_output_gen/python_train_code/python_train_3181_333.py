import math
n = int(input())
a = [int(input()) for _ in range(n)]
print(math.ceil(n/min(a))+4)