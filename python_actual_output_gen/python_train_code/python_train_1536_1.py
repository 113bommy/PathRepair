
n = int(input())
l = list(map(int, input().split()))

co = 0
i = 0
while i < n:
	if l[i] == 1:
		l[i] = 0
		co += 1

	if 1 in l and l.index(1) - i > 1:
		i = l.index(1)
		co += 1
	else:
		i += 1

print(co)

