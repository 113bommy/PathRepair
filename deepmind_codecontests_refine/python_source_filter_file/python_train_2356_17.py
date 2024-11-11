n, xs, i = int(input()), [int(x) for x in input().split()], 0
for i in range(1, len(xs) - 2):
	if xs[i] > xs[i-1] and xs[i] > xs[i+1]: i += 1
	elif xs[i] < xs[i-1] and xs[i] < xs[i+1]: i += 1
print(i)
