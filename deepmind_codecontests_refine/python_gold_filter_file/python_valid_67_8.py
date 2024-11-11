import math

t = int(input())

for i in range(t):
	a, b, c = [int(x) for x in input().split()]
	nop = (abs(a-b) - 1)*2 + 2
	# print(nop)

	if a > nop or b > nop or c > nop:
		print(-1)

	else:
		print((a - 1 - (b - c))%nop + 1)

