def f(n,t):
	a=1
	while True and a<=n:
		t-=a
		if t<0:
			return int(t+a)
		else:
			a+=1

n,t=input().split()
n=int(n)
t=int(t)
sum=n*(n+1)/2
if t>sum:
	t=t%sum
print(f(n,t))