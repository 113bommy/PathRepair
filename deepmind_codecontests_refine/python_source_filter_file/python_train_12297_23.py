q=int(input())
for i in range(q):
	l,r=[int(x) for x in input().split()]
	if (r-l)%2==1:
		if l%2==1:
			print(int(-(r-l+1)/2))
		else:
			print(int(-(r-l+1)/2))
	else:
		if l%2==1:
			print(int(-l-(r-l)/2))
		else:
			print(int(r-(r-l)/2))
