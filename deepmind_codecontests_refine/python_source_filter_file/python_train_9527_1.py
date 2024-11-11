import sys

def main():
	k, n, m = input().split(" ")
	num_plates = int(k)
	num_lines = int(n)
	num_chars = int(m)

	input()

	plates = []
	visited = []
	for layer in range(num_plates):
		
		plate = []
		visit = []
		for line_num in range(num_lines):

			plate.append(input().split(" "))

			v = []
			for c in range(num_chars):
				v.append(False)
			visit.append(v)

		plates.append(plate)
		visited.append(visit)
		input()

	x, y = input().split(" ")
	x = int(x)
	y = int(y)
	print(water_flow(plates, visited, 0, x-1, y-1, num_lines, num_chars))

def water_flow(plates, visited, layer, x, y, num_lines, num_chars):
	if (0 <= layer < len(plates)) and (0 <= x < num_lines) and (0 <= y < num_chars):
		if not visited[layer][x][y]:
			square = plates[layer][x][0]
			sqr = square[y]
			visited[layer][x][y] = True

			if sqr == ".":
				minutes = 1

				minutes += water_flow(plates, visited, layer-1, x, y, num_lines, num_chars)
				minutes += water_flow(plates, visited, layer, x-1, y-1, num_lines, num_chars)
				minutes += water_flow(plates, visited, layer, x-1, y, num_lines, num_chars)
				minutes += water_flow(plates, visited, layer, x-1, y+1, num_lines, num_chars)
				minutes += water_flow(plates, visited, layer, x, y-1, num_lines, num_chars)
				minutes += water_flow(plates, visited, layer, x, y+1, num_lines, num_chars)
				minutes += water_flow(plates, visited, layer, x+1, y-1, num_lines, num_chars)
				minutes += water_flow(plates, visited, layer, x+1, y, num_lines, num_chars)
				minutes += water_flow(plates, visited, layer, x+1, y+1, num_lines, num_chars)
				minutes += water_flow(plates, visited, layer+1, x, y, num_lines, num_chars)

				return minutes

	return 0


main()
