import math
n = int(input())
ans = math.factorial(n) % (1e9+7)
print(int(ans))