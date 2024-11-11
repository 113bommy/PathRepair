polyhedrons = {
    "tetrahedron" : 4,
    "cube" : 6,
    "octahedron" : 10,
    "dodecahedron" : 12,
    "icosahedron" : 20
}
n = int(input())
res = 0
for line in range(0, n):
    x = input().lower()
    res += polyhedrons[x]

print(res)