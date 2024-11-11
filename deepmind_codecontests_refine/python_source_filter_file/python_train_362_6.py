import math
n, m = map(int, input().split())
numbers = [0 for i in range(m)]
for item in map(int, input().split()):
	numbers[item-1] += 1
ans = n*(n-1)/2
for item in numbers:
	ans -= item*(item-1)/2
print(ans)