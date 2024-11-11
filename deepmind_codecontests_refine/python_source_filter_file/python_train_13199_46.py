n=int(input())
l=2
for i in range(2,int(n**0.5)):
	if n%i==0:
		l=i
k=n//l
print(l+k-2)