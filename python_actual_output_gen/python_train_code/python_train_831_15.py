n = int(input()); a = list(map(int, input().split(' ')))
prefix = [0]*n; prefix[0] = a[0]
for i in range(n): prefix[i] = a[i] + prefix[i-1]

turn, stop, took = 0, -1, 0
while stop != n-1:
	mod, oldStop = (turn + 1) % 2, stop
	if mod == 1: #First player
		for j in range(n-1, stop, -1):
			if (prefix[j] - took) % 2 == 1:
				stop = j; took = prefix[j]; break
	else:
		for j in range(stop+1, n):
			if (prefix[j] - took) % 2 == 0:
				stop = j; took = prefix[j]; break

	if stop == oldStop: break
	turn += 1

print("First" if turn % 2 == 1 else "Second")