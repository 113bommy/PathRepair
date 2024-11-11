import collections

def compute_coorinate(data):
	return int(eval(data))


if __name__ == "__main__":
	m = int(input())
	coordinates = []
	for i in range(m):
		coordinates.append(compute_coorinate(input()))
	numbers = collections.Counter(coordinates)
	print(" ".join(str(numbers[x]) for x in coordinates))