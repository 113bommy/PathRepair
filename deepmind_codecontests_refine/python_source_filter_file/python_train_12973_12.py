import math
n = int(input())
a = int(math.sqrt(n))
b = n - a * a
ans = 4 * a + 2 * (b > 0) + 2 * (b >= a)
print(ans)