q=int(input())
sol=[]
while q>0:
	n,a,b = input().split()
	n=int(n)
	a=int(a)
	b=int(b)
	if n%2==0:
		costB = (b*n)/2
	else :
		costB = (b*(n-1))/2 + a
	costA = n*a
	if costA>costB:
		sol.append(costB)
	else:
		sol.append(costA)
	q -= 1
for ele in sol:
	print(ele)
	