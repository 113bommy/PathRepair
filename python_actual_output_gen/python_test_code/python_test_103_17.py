
this_dict={
"Icosahedron" : 20,
"Dodecahedron" : 12,
"Octahedron" : 8,
"Cube" : 4,
"Tetrahedron" : 3,
}
y=list()
n=int(input())
t = 0
for i in range(1,n+1):
	ai=input()
	t = t + this_dict[ai]
print(t)