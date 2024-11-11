for __ in range(int(input())):
	n,a,b=map(int,input().split())
	ar1=list(map(int,input().split()))
	ar2=list(map(int,input().split()))
	if(max(ar1)>max(ar2)):
		print("YES")
	print("NO")