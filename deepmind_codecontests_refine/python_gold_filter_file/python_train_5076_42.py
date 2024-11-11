n, coins = map(int, input().split())
sequence = list(map(int, input().split()))

n_odd = 0
n_even = 0
cuts = []
n_cuts = 0
ans = 0

for i in range(n):
	if n_odd == n_even and n_even != 0:
		cuts.append(sequence[i] - sequence[i - 1])
		if cuts[n_cuts] < 0:
			cuts[n_cuts] *= -1
		n_cuts += 1
	if (sequence[i] % 2 == 0):
		n_even += 1
	else:
		n_odd += 1

cuts.sort()
for i in range (n_cuts):
	coins -= cuts[i]
	if (coins >= 0):
		ans += 1
	else:
		break
print(ans)

