a,b = map(int,input().split())
v = []
for i in range(a):
	z = input()
	if z.count("*")>0:
		for j in range(len(z)):
			if z[j]=="*":
				v.append([i,j])
if v[0][0]==v[1][0]:
	if v[0][1]==v[2][1]:
		print(v[2][0]+1,v[1][1]+1)
	else:
		print(v[2][0]+1,v[0][1]+1)

else:
	if v[0][1]==v[2][1]:
		print(v[0][0]+1,v[1][1]+1)
	else:
		print(v[0][0]+1,v[0][1]+1)