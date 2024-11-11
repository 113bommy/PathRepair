t = int(input())

while(t!=0):
	t-=1
	n, k = [int(x) for x in input().split()]
	s = list(input())
	ind = []

	for i in range(len(s)):
		if(s[i] == "1"):
			ind.append(i)


	ctr = 0

	if(len(ind) == 0):
		if(n%(k + 1) != 0):
			print((n // (k + 1))  + 1)
		else:
			print(n//(k + 1))
		continue

	if(len(ind) > 0):
		if(ind[0] > 0):
			ctr += (ind[0])//(k+1)
		if(n - 1 - ind[-1] - k > 0):
			ctr+= (n - 1 - ind[-1] - k)//(k+1)

	if(len(ind) > 1):
		for i in range(1, len(ind)):
			x = ind[i] - ind[i - 1] - 1
			if(x - k > 0):
				ctr+= (x-k)//(k+1)

	print(ctr)

	






















