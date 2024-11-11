
a = int(input())

for i in range(0,a):
	A = input()
	B = input()
	p = False
	L1= len(A)
	L2= len(B)
	i=L1-1
	j=L2-1
	T=0
	while i > 0 and j >= 0:
		if A[i]==B[j]:
			i= i-1
			j= j-1
			p = True
			T=T+1
		else :
			'''A=A[:i-1]+A[i+1:]'''
			i=i-2
			p = False

	if T==L2:
		print ("Yes")
	else:
		print ("No")

