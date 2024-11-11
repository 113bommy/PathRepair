def numberOfSymbols(x):
	count = 0
	while x >= 1:
		x //= 10
		count += 1
	return count

t = int(input())

for i in range(t):
 	a = [int(x) for x in input().split()]
 	print(a[0] * (numberOfSymbols(a[1]) - 1))