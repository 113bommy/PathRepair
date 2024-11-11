t = int(input())
if not 1 <= t <= 10**3:
	exit()

results = []

for i in range(t):
	n = int(input())
	if not 1 <= n <= 100:
		exit()
	a = [int(item) for item in input().split(' ') if -100 <= int(item) <= 100]
	if len(a) != n:
		exit()
	summation = sum(a)
	zeros = a.count(0)
	results.append((zeros + 1) if summation + zeros == 0 else zeros)

[print(item) for item in results]
