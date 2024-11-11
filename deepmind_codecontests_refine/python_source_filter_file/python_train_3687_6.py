data = input().split(" ")
tasks = int(data[0])
k = int(data[1])
cost = input().split(" ")
cost = [int(x) for x in cost]
minCost = 100000
ans = 1
for i in range(k):
	start = i
	c = 0
	for j in range(start, tasks, k):
		c += cost[j]
	if c < minCost:
		minCost = c
		ans = i+1
print(ans)


