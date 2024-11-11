n = int(input())
costs = list(map(int, input().split()))
words = []
for _ in range(n):
	words.append(input())

cost, costInv = 0, costs[0]
for i in range(1, n):
	newCost, newCostInv = float('inf'), float('inf')
	if words[i] > words[i-1]:
		newCost = min(newCost, cost)
	if words[i] > words[i-1][::-1]:
		newCost = min(newCost, costInv)

	if words[i][::-1] > words[i-1]:
		newCostInv = min(newCostInv, cost+costs[i])
	if words[i][::-1] > words[i-1][::-1]:
		neCostInv = min(newCostInv, costInv+costs[i])

	cost = newCost
	costInv = newCostInv
	if min(cost, costInv) == float('inf'):
		print(-1)
		break

if min(cost, costInv) < float('inf'):
	print(min(cost, costInv))