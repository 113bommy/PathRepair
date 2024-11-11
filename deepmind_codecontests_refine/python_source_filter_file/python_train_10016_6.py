for _ in range(int(input())):
	n, m=map(int, input().split())
	a=[x-1 for x in list(map(int, input().split()))]
	b=[x-1 for x in list(map(int, input().split()))]
	pos = a[:]
	for i in range(n):
		pos[a[i]] = i
	ans=m;
	lst=-1;
	for i in range(m):
		if pos[b[i]]>lst:
			ans+=2*(pos[b[i]]-i)
		lst=pos[b[i]]
	print(ans)
