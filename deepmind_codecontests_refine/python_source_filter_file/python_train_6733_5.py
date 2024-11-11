(n, k, l) = [int(i) for i in input().split()]
lengths = input().split()
for i in range(n * k):
	lengths[i] = int(lengths[i])

lengths.sort()

smallest = lengths[0]
biggest = smallest + l

stop = len(lengths)
for i in range(len(lengths)):
	if lengths[i] > biggest:
		stop = i
		break

if stop < n:
	print(0)

else:
	ans = 0
	pos = 0
	todo = n
	for i in range(n):
		ans += lengths[pos]
		pos += 1
		for j in range(k - 1):
			if (stop - pos) > n - i:
				pos += 1



	print(ans)