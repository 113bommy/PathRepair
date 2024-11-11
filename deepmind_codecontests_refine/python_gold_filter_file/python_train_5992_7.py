n = int(input())
lt = [int(_) for _ in input().split()]
av = sum(lt) // (n // 2)

def find(val):
	for i in range(n):
		if lt[i] == -1:
			continue
		if lt[i] == val:
			return i
	return -1

for i in range(n):
	if lt[i] == -1:
		continue

	p = av - lt[i]

	lt[i] = -1
	pi = find(p)
	print(str(i + 1) + " " + str(pi + 1))
	lt[pi] = -1