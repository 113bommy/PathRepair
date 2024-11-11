n,k=list(map(int,input().split()))
t=list(map(int,input().split()))
t.sort(reverse=True)
for i in  t:
	if k%i==0:
		print(n//i)
		exit(0)