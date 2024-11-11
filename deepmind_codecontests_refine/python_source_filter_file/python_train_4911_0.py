n=int(input())
r=0
for i in range(n+1):
	bl=2*n-r
	rs=0
	c=0
	for j in range(2*n+1):
		rs+=1
		if rs<=bl//2:
			print(" ",end=" ")
		elif j<=n+i:
			if j<n:
				print(c,end=" ")
				c+=1
			elif j==n:
				print(c,end="")
			else:
				c-=1
				print("",c,end="")
	r+=2
	print()
r=2
for i in range(n):
	bl=r
	rs=0
	for j in range(2*n+1):
		rs+=1
		if rs<=bl//2:
			print(" ",end=" ")
		elif j<=2*n-i-1:
			if j<n:
				print(c,end=" ")
				c+=1
			elif j==n:
				print(c,end="")
			else:
				c-=1
				print("",c,end=" ")
	r+=2
	print()