q=int(input())
for i in range(q):
	n=int(input())
	a=list(map(int,input().split()))
	flag=0
	if n==1 or n==1:
		print("YES")
	else:

		l=a[0]
		j=a[1]
		abc=0
		if j==l+1:
			flag=1
		elif j==1 and l==n:
			flag=1
		elif j==l-1:
			flag=0
		elif j==n and l==1:
			flag=0
		#print(flag)
		if flag==0:

			for b in range(2,n):
				k=a[b]
				if k==j-1:
					flag=0
				elif j==1 and k==n:
					flag=0
				else:
					flag=1
				j=k
				#print(flag)
				if flag==1:
					abc=1
					print("NO")
					break


		else:
			for b in range(2,n):
				k=a[b]
				if k==j+1:
					flag=1
				elif j==n and k==1:
					flag=1
				else:
					flag=0
				#print(flag)
				j=k
				if flag==0:
					abc=1
					print("NO")
					break
		if(abc==0):

			print("YES")


