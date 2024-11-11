import math

def main():
	t = int(input())
	for _ in range(t):
		n, c = (int(x) for x in input().split())
		L1 = [int(x) for x in input().split()]
		L2 = [int(x) for x in input().split()]
		print(solver, n, c, L1, L2)

def solver(n, c, L1, L2):
	minDays = math.ceil(c / L1[0])
	days = 0
	money = 0
	for i in range(n - 1):
		if days >= minDays:
			return minDays
		daysToBuy = math.ceil((c - money) / L1[i])
		if days + daysToBuy < minDays:
			minDays = days + daysToBuy
		daysToNextJob = math.ceil((L2[i] - money) / L1[i])
		if daysToNextJob > 0:
			days += daysToNextJob + 1
			money += daysToNextJob * L1[i] - L2[i]
		else:
			days += 1
			money -= L2[i]
	daysToBuy = math.ceil((c - money) / L1[n - 1])
	if days + daysToBuy < minDays:
		minDays = days + daysToBuy
	return minDays

main()
	#while i <= maxDays and i < n:
	#	daysToBuy = 

#print(solver(4, 15, [1, 3, 10, 11], [1, 2, 7]))
#print(solver(4, 100, [1, 5, 10, 50], [3, 14, 12]))