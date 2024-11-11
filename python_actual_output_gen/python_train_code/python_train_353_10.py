a, b = [int(i) for i in input().split()]
c, d = [int(i) for i in input().split()]

z = min(b,d)
while True:
	if z % a == b % a and z % c == d % c:
		print(z)
		break
	elif z>100*100:
		print(-1)
		break
	z += 1