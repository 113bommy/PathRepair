t=int(input())

for _ in range(t):
	n=int(input())
	ad=False
	for i in range(2,101):
		if (n%i==0):
			ln1=n//i
			n1=i
			#print("n1 = ",n1)
			for j in range(i+1,101):
				#print("ln1(rem)j = ",ln1%j)
				if (ln1%j==0 and j*j!=ln1 and ln1//j!=i and ln1//j!=1):
					ln2=ln1//j
					n2=j
					n3=ln2
					print("YES")
					print(n1,n2,n3)
					ad=True
					break
				if (ad==True):
					break
			if (ad==True):
				#print("NO")
				break
		if (ad==True):
			break

	if (ad==False):
		print("NO")