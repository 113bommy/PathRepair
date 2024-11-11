n,a,b=map(int,input().split())	
ai=list(map(int,input().split()))
bi=list(map(int,input().split()))
ai.sort()
i=1
j=0
while i<=n and j<a:
	if i==ai[j]:
		print(1,end=" ")
		i=i+1
		j=j+1
	else:
		print(2,end=" ")
		i=i+1
for i in range(a,n):
	print(2,end=" ")