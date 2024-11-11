n=int(input())

for i in range(5):
	a=list(str(n))
	a=[int(i) for i in a]
	if(sum(a)%4==0):
		for i in a:
			print(i,end="")
		break
	else:
		n+=1

