k = int(input())
a = input()
b = list(map(int,a.split()))
b.sort()
sum = 0
if k == 0:
	print (0)
else:
	for i in range(12):
		sum = sum + b[12 - i - 1]
		if sum >= k:
			print(i + 1)
			break
		if sum < k and i == 12:
			print(-1)