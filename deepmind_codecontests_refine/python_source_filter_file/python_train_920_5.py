
def solve(n, x, a):
	costs = []
	cost_min = 0
	for k in range(n):
		if k == 0:
			costs = a.copy()
		else:
			for i in range(n):
				costs[i] = min(costs[i], a[(i-k)%n])
		cost_k = sum(costs) + k*x
		if k == 0:
			cost_min = cost_k
		else:
			cost_min = min(cost_min, cost_k)
			if cost_min != cost_k:
				break
		if cost_min < (k+1) *x:
			break
 
	return cost_min
n, x = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
print(solve(n,x,a))