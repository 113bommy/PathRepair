minutes = [int(i) for i in input().split()]
tries = [int(i) for i in input().split()]
hs, hu = [int(i) for i in input().split()]
amount = 100*hs - 50*hu

curr = 0

for i in range(5):
	curr = 500 * (i + 1)
	amount += max(0.3*curr, (1 - minutes[i]/250)*curr - 50*tries[i]);

print(amount)