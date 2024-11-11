l=[]
for i in range(3):
	s=input()
	l.append(list(s))
if l[0][0]==l[2][2] and l[0][1]==l[2][1] and l[0][2]==l[2][0] and l[1][0]==l[1][2] :
	print("YES")
else:
	print("NO")