n=int(input())
l=[]
for i in range(n):
	si=str(input())
	l.append(si)

for i in range(0,n):
	if l[i] in l[0:i]:
		print("yes")
	else:
		print("no")