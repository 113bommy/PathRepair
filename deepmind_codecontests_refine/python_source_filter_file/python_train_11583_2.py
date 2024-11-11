test = int(input())
for _ in range(test):
	n, k = map(int, input().split())
	arr = list(input())
	last = -1
	total = 0
	for i in range(n):
		if arr[i]=='1':
			if last==-1:
				total+=(i-0)//(k+1)
			else:
				av = i-last-1
				if av!=0:
					total+=(av-1)//(k+1)

			last = i
	if last==-1:
	    print(1+((n-1)//(k+1)))
	else:
	    total+=(n-1-last)//(k+1)
	    print(total)