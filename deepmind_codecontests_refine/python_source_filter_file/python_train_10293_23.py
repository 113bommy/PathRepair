import math

N = int(input())
a = [int(i) for i in input().split()]
b = math.round(sum(a)/N)

c = sum([(i - b)**2 for i in a])
print(c)