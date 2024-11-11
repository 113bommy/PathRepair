t = int(input())

cache = []
for x in range(1, 10001):
	if x % 3 or str(x)[-1] == '3':
		continue
	cache.append(x)

for _ in range(t):
	print(cache[int(input())])