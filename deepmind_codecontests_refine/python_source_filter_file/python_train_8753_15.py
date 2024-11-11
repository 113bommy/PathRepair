n,k,s=map(int,input().strip().split())
d=n-1
if (d*k<s or k>s):
	print ("NO")
	exit(0)
else:
	print ("YES")
if (n==2):
	for i in range(k):
		if (i%2==0):
			print (2,end=" ")
		else:
			print (1,end=" ")
	exit(0)
e=s-k
r=n-2
f=e//r
g=e%r
if (g==0):
	re=k-f
else:
	re=k-f-1
se=1
for i in range(f):
	if (i%2==0):
		print (n,end=" ")
		se=n
	else:
		print (1,end=" ")
		se=1
if (g!=0):
	if (se==1):
		print (2+g,end=" ")
		se=2+g
	else:
		print (10-g-1,end=" ")
		se=10-g-1
count=0
while(re!=count):
	if (se==n):
		if (count%2==0):
			print (n-1,end=" ")
		else:
			print (n,end=" ")
	else:
		if (count%2==0):
			print (se+1,end=" ")
		else:
			print (se,end=" ")
	count=count+1