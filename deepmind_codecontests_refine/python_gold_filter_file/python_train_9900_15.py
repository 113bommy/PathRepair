tmp=input().split()
n=int(tmp[0])
k=int(tmp[1])
a=b=0
if(n==1 or k<3):
	print("0")
else:
	if(n==2 and k==3):
		print("1")
	else:
		if(3<=k and k<=2*n-1):
			if(3<=k and k<=n+1):
				b=k-1
				a=1
			else:
				b=n
				a=k-n
			if(k%2):
				print(int((b-a)/2)+1)
			else:
				print(int((b-a)/2))
		else:
			print("0")