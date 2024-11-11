import math
n = int(input())
s = [int(input()) for i in range(n)]
print(math.ceil(n/min(s))+4)