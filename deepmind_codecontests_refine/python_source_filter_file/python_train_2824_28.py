def iter_from_input():
	return map(int, inpit().split())


def solve(n, k, colors):
	colors = iter(colors)
	previous_color = next(colors)
	current_length = 1
	max_length = current_length
	for color in colors:
		if color == previous_color:
			max_length = max(max_length, current_length)
			current_length = 1
		else:
			current_length += 1
		previous_color = color

	# For last iteration
	max_length = max(max_length, current_length)
		
	return max_length

def test():
	assert (solve(4,1, (1,1,1,1)) == 1)
	assert (solve(4,2, (1,1,1,2)) == 2)
	assert (solve(4,2, (2,1,2,1)) == 4)

test()

def main():
	n, k = iter_from_input()
	colors = list(iter_from_input())
	result = solve(n, k, colors)
	print(result)

# main()