# Preprocessing input
n_cups, target = [int(i) for i in input().split()]
cups = [int(i) for i in input().split()]
cups = sorted(cups, reverse=True)
found = False

if sum(cups) < target:
	print(-1)
	found = True

# Helper function
def find_value(c, days):
	val = 0
	for i in range(len(c)):
		val += max(c[i] - i // days, 0)
	return val

# Binary search
low = 1
high = n_cups

while not found:
	current = (low + high) // 2
	val = find_value(cups, current)
	if low == current or high == current:
		if val > target:
			print(current)
			found = True
			break
		else:
			print(current + 1)
			found = True
			break
	if val < target:
		low = current
	elif val > target:
		high = current
	else:
		print(current)
		found = True
		break