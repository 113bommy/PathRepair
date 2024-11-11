n=int(input())
li=list(map(int,input().split()))
m=-10**9
for i in range(3,n+1):
	if(n%i==0):
		for j in range(0,n//i):
			m=max(m,sum(li[j:n:n//i]))
print(m)
