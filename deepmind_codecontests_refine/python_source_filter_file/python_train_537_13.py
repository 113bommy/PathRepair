for _ in range(int(input())):
	n, k, d = map(int,input().split())
	l = list(map(int,input().split()))
	k1 = []
	for i in range(0,n,d):
		if i<=n-d:
			k1.append(len(set(l[i:i+d])))
	print(min(k1))