import heapq as hq
import math

a, b, x, y = [int(i) for i in input().split(" ")]
g = math.gcd(x, y)
x /= g
y /= g
print(min(a // x, b // y))