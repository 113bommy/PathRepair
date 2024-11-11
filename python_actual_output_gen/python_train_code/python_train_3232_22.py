n, k, m=map(int,input().split())

l=list(map(int,input().split()))
l.sort()
s=sum(l)

maxavg=(s+min(m, (n)*k))/n


for i in range(min(n-1,m+1)):
	s=s-l[i]
	newsum=s+min(m-i-1, (n-i-1)*k)
	
	newavg=newsum/(n-i-1)
	#print(newavg)
	maxavg=max(maxavg,newavg)

print(maxavg)