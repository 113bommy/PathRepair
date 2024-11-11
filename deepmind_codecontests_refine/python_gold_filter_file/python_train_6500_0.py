n = int(input())
stones = [int(x) for x in input().split(' ')]
sorted_stones = sorted(stones)
m = int(input())
answers = []

sums = [[0] * (n+1), [0] * (n+1)]
for i in range(n):
	sums[0][i+1] = sums[0][i] + stones[i] #unsorted
	sums[1][i+1] = sums[1][i] + sorted_stones[i] #sorted

for i in range(m):
	t, l, r = [int(x) for x in input().split(' ')]
	if t == 1:
		answers.append(sums[0][r] - sums[0][l-1])
	else:
		answers.append(sums[1][r] - sums[1][l-1])

# print(sums)
print('\n'.join([str(x) for x in answers]))