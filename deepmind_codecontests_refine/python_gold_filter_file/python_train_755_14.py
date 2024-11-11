t=int(input())
for _ in range(t):
	n=int(input())
	l=list(map(int, input().split()))
	if len(list(set(l)))==1:
		print(-1)
	else:
		i=l.index(max(l))
		j=i+1
		while(j<n and l[j]==l[i]):
			j+=1
		if j==n and l[j-1]==l[i]:
			j=i+1
		print(j)
