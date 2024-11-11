n = int(input())
trees = []
for i in range(n):
	x, h = map(int, input().split())
	trees.append((x, h))
felled = 2
for i in range(1,n-1):
	left = trees[i][0] - trees[i][1]
	right = trees[i][0] + trees[i][1]
	if left > trees[i-1][0]:
		felled += 1
	elif right < trees[i+1][0]:
		felled += 1
		trees[i] = (trees[i][0] + trees[i][1], trees[i][1])
print(felled)
