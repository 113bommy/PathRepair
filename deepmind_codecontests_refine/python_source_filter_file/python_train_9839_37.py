import math
t = int(input())
for i in range(t):
	n = int(input())
	print(int(((n * (n + 1)) / 2)) - 2 * (int(pow(2, int(math.floor(math.log(n, 2))) + 1)) - 1))