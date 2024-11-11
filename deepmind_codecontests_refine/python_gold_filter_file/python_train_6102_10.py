n=int(input())

l=list(map(int,input().split()))

if((n%2)==0):
	print("No")
else:
	if(l[0]%2!=0 and l[n-1]%2!=0):
		print("Yes")
	else:
		print("No")

