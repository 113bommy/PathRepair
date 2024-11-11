n,m,k = map(int,input().split())
if k == 1:
	print(pow(2,(n-1)*(m-1),1000000007))
else :
	if n-m %2 != 0:
		print(pow(2,(n-1)*(m-1),1000000007))
	else: print(0)