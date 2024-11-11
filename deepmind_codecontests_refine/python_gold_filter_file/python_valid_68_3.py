for t in range(int(input())):
	n = int(input())
	i=0
	while i*i < n:
		i+=1

	d = i*i-n+1
	k=d-i


	if d>=i:
		print(i-k,i)
	else:
		print(i,i*i-n+1)