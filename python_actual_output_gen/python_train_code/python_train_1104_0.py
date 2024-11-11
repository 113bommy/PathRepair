n=int(input())
a=list(map(int,input().split()))
a.sort()
l=[]
p=0
i=0
while len(l)!=n:
	if p==0:
		l.append(a[i])
	else:
		l.append(a[n-i-1])
		i+=1
	p=p^1
print(l) 