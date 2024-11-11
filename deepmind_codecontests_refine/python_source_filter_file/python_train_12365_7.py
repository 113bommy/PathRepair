n,k=map(int,input().split())
ar=list(map(int,input().split()))
for i in range(k,n):
	if ar[i]>ar[i-k]:
		print("Yes")
	else:
		print("No"