k = int(input())
a = input()
b = list(map(int,a.split()))
b.sort()
sum = 0
if k == 0:
	print (0)
else:
	for i in range(12):
		sum = sum + b[11 - i]
		if sum >= k:
			print(i + 1)
			break
		if sum < k and i == 11:
			print(-1)