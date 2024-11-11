N=int(input())
for h in range(1,3501):
	for n in range(1,3501):
		A=N*h*n
		B=4*h*n-N*n-N*h
		if B<=0:
			continue
		if A%B==0:
			print(h,n,A//B)
			exit()
