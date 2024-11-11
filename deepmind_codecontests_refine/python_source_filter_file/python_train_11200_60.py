n=int(input())
s=0
d={'Tetrahedron':4,'Cube':6,'Octahedron':8,'Dodecahedron':12,'Icosehadron':20}
for i in range(n):
	a=input()
	if a=='Tetrahedron':
		s=s+d['Tetrahedron']
	elif a=='Cube':
		s=s+d['Cube']
	elif a=='Octahedron':
		s=s+d['Octahedron']
	elif a=='Dodecahedron':
		s=s+d['Dodecahedron']
	elif a=='Icosehadron':
		s=s+d['Icosehadron']
print(s)