import math

n = int(input())
x = math.ceil(math.sqrt(n))
ans = x * math.ceil(n / x)
print(ans)

