import math
n = int(input())
a = [int(x) for x in input().split()]
print(max(math.ceil(sum(a)/n*2), max(a)))