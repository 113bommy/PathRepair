tensum = {0: 0, 1: 45, 2: 40, 3: 45, 4: 40, 5: 25, 6: 40, 7: 45, 8: 40, 9: 45}

t = int(input())

for tc in range(t):
	n, m = map(int, input().split(' '))
	sum1 = 0
	ud = 1337 % 10	# units digit of the divisor
	rangeMax = n//m
	sum1 += (rangeMax//10) * tensum[ud]
	for i in range(1, rangeMax%10+1):
		sum1 += (i*m)%10
	print(sum1)