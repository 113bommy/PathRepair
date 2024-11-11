a = int(input())

def add(num):
	num = str(num)
	ans = 0
	for i in num:
		ans += int(i)
	return ans

for i in range(a, 1010):
	tot = add(i)
	if tot % 4 == 0:
		print(i)
		break