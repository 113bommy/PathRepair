import sys
import math
n = int(input())
ans = 1 + n
for i in range(1,int(math.sqrt(n)) + 1):
	ans = min(ans, i + int(math.ceil((n / i))))
print(ans)
