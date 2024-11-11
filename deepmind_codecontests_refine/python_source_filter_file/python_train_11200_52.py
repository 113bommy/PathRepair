n=int(input())
f=0
for i in range(0,n):
	s=str(input())
	if(s=="Icosahedron"):
		f+=20
	elif(s=="Cube"):
		f+=6
	elif(s=="Tetrahedron"):
		f+=4
	elif(s=="Dodecahedron"):
		f+=12
	elif(s=="Icosahedron"):
		f+=20
	else:
		f+=0
print(f)