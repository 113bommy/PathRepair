def Sum(n):
	return (n*(n+1))//2

def	check(n):
	limit = int((2*n)**(1/2))
	k=limit
	while 0<k<=limit:
		l = 1
		u =	k+1
		while u!=l  :
			print(u,l,k)
			mid = int((l+u)/2)
			curr = Sum(mid)+Sum(k)
			if curr == n:
				return 'YES'	
			elif curr > n :
				if u == mid :
					break
				u = mid
			else :
				if l == mid:
					break
				l = mid		
		k-=1
	return 'NO'

n = int(input())
print(check(n))		
