vstup1 = int(input())
for i  in range(vstup1):
	vstup2 = list(map(int,input().split()))
	n = vstup2[0]
	k = vstup2[1]
	counter = 0
	while n:
		if n % k:
			zvysok = n%k
			n -= zvysok
			counter += zvysok
		else:
			n = n//k
			counter += 1

	print(int(counter))
 


