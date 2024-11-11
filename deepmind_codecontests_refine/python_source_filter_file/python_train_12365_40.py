n,k=map(int,input().split())
a=list(map(int,input().split()))
s=sum(a[:k])
for i in range(n-k):
	t=sum(a[i+1:k+i+1])
	print('YNeos'[s>=t::2])
	s=t