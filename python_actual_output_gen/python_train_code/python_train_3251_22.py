def ehab(L):
	n=len(L)
	for i in range(n-1,1,-1):
		print(L)
		if(L[i]<L[i-1]+L[i-2]):
			return "YES"
	return "NO"

n=int(input())
L=list(map(int,input().split()))
L.sort()
print(ehab(L))
