n=int(input())
for i in range(n):
	a=input()
	ind1=0
	ind2=0

	for i in range(len(a)):
		if a[i]=='1':
			ind1=i
			break

	# print(ind1)


	a=a[::-1]
	for i in range(len(a)):
		if a[i]=='1':
			ind2=i
			break


	if ind1==ind2 and ind2==0:
		print("0")
	else:
		ind2=len(a)-ind2-1
		# print(ind2)
		a=a[::-1]
		cnt=0
		if ind1==ind2:
			print("0")
		else:

			for i in range(ind1,ind2+1):
				if a[i]=="0":
					cnt=cnt+1

			print(cnt)