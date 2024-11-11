q = int(input())

for i in range(q):
	n = int(input())
	p = list(map(int, input().split()))

	m = [1]*n

	for j in range(n):

		if(m[p[j]-1]==1):

			min_m = {}
			last = j
			min_m[j] = j
			
			while(p[min_m[last]]-1 not in min_m):
				min_m[p[min_m[last]]-1] = p[min_m[last]]-1
				last = p[min_m[last]]-1
				
			for k in min_m:
				m[k] = len(min_m.keys())

	for k in m:
		print(k, end=" "	)
	print("")