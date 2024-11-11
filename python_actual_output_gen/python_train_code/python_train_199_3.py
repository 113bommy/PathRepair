q = int(input())
for _ in range(q):
	n = int(input())
	k = n//2
	su = k*(k+1)//2
	su += (2*k*(k*(k+1)//2))
	su *= 4
	print(su)
	