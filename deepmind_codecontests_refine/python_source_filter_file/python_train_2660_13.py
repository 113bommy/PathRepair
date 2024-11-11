def main():
	sticks = [int(x) for x in input().split()]
	print(solver(sticks))

def solver(sticks):
	sticks.sort()
	if sticks[0] + sticks[1] > sticks[2] or \
	sticks[1] + sticks[2] > sticks[3]:
		return "TRIANGLE"
	elif sticks[0] + sticks[1] == sticks[2] or \
	sticks[1] + sticks[2] == sticks[3]:
		return "SEGMENT"
	else:
		return "IMPOSSIBLE"

#print(solver([4, 2, 1, 3]))
#print(solver([7, 2, 2, 4]))
#print(solver([3, 5, 9, 1]))