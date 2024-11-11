def Gen(a, k):
	while(1):
		yield (a - 1) * k
		a += 2
		k += 1

num = int(input())

for _ in range(num):
	#n, k = [int(i) for i in input().split()]

	n = int(input())
	ans = 0

	if n == 3:
		print(0)
	else:
		gen = Gen(3, 1)
		for i in range(n // 2):
			ans += next(gen) * 4
	
	print(ans)