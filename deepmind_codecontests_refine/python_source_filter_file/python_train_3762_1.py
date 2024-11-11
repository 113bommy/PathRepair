n=int(input())
a=sorted(list(map(int,input().split())))
m=0
for i in range(n//2):
	m+=a[i]+a[n-1-i]
print(m)