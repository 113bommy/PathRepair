n,k = map(int,input().split())
s = [int(i) for i in input().split()]
b = 0
r = 0


while b<n:
	d = s.copy()
	
	x = [i for i in range(-b,n,k) if i>=0]
	
	for i in x:
		d[i] = 0
	
	c = abs(d.count(-1)-d.count(1))
	
	r = max(c,r)

	b+=1

print(r)
