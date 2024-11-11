n=int(input())
xyz=0
for i in range(n):
	str=input()
	if(str=="++x" or str=="x++"):
		xyz+=1
	elif(str=="--x" or str=="x--"):
		xyz-=1
print(xyz)
