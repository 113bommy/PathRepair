t=int(input(""))
for i in range(0,t):
	a=input("")
	sum=0
	for j in a.split(" "):
		sum=int(j)
	print(sum//2)