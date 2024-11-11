n=int(input())

l=list(map(int,input().split()))
l.sort()
sum1=0
sum2=0

for i in range(n):
	sum1=sum1+l[i]
	sum2=sum2+l[2*n-1-i]

if (sum1==sum2):
	print("-1")
else:
	for i in range(2*n):
		print(l[i],end=" ")