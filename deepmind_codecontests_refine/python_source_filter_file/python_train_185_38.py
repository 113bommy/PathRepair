N,P=list(map(int,input().split()))

root=P**(1/N)
x=int(root)

for i in range(x):
	if P%((x-i)**N)==0:
		print(x-i)
		break
