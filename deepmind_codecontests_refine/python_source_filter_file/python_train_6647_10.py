n,a=int(input()),list(map(int,input().split()))
if sum(a)%(n*(n+1)/2):
	print("NO")
else:
	k=sum(a)/(n*(n+1)/2)
	a+=[a[0]]
	if sum([(k-i+j)%n for i,j in zip(a[1:],a)]) or sum([(k-i+j)/n for i,j in zip(a[1:],a)])!=k:
		print("NO")
	else:
		print("YES")