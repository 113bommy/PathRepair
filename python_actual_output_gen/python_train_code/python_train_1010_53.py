n,k = input().strip().split()
n,k = [int(n),int(k)]
tmp = []
if(n==k):
	tmp = [0,0]
else:
	tmp = [1,min(n-k,2*k)]
print(" ".join(map(str,tmp)))