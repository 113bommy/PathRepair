n = int(input())
nums =[ int (x) for x in input().split()]
bal=0
p=0
ng=0
ans=0
for i in nums:
	if bal%2==0:
		p+=1
	else:
		ng+=1
	if i<0:
		bal+=1
	if bal%2==0:
		ans=ans+p
	else:
		ans=ans+ng
tot=n*(n+1)//2
print(ans, tot-ans)