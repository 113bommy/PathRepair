n , k = map(int,input().split())
a = [int(i) for i in input().split()][:n]
d = 0
e = 0
if k > sum(a):
	print(-1)
else:
	for item in a:
		if item+e >= 8:
			k-=8
			e += (item-8)
		else:
			k-=item+e
		d+=1
		if k <= 0:
			print(d)
			break
		if d == n:
			print(-1)
			break