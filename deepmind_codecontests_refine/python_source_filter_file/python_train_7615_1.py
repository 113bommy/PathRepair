t = int(input())

for _ in range(t):
	n,k = map(int,input().split())
	s = 0

	while n > 0:
		
		if n%k:
			r = n%k
			s += r
			n-=r

		else:
			n *= (1/k)
			s+=1 

	print(int(s))

