n=int(input())
a=list(map(int,input().split()))
q=0
for x in range(n):
	if x%2==1:
		if a[x]%2==1:
			q+=1
print(q)