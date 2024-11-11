n, m = int(input()), 0
b = [int(t) for t in input().split()]
a = []
for i in range(n):
	a.append(b[i])
	while len(a) > 1 and a[-2] == a[-1]:
		del a[-1]
		a[-1] *= 2
print(len(a))
print(" ".join([str(t) for t in a]))