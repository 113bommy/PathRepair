def get_number_of_sides(polyhedron):
	if polyhedron == 'Tetrahedron':
		return 4
	elif polyhedron == 'Cube':
		return 6
	elif polyhedron == 'Octahedron':
		return 8
	elif polyhedron == 'Dodecahedron':
		return 12
	else:
		return 16

n = int(input())
facets = 0
i = 0
while i < n:
	facets += get_number_of_sides(input())
	i += 1
print(facets)