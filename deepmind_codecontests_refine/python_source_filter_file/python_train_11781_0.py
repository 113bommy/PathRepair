nz = [int(x) for x in input().split()]

edges = set()
divisors = set()

for x in range (0,nz[1]):	
	uv = [ y for y in input().split()]
	edges.add(uv[0] + ' ' + uv[1])

for x in range(2,nz[0]):
	if nz[0] % x == 0:
		divisors.add(x)


flag = 0

for y in divisors:
	flag = 0
	for x in edges:
		u = (int(x.split()[0]) + y) % nz[0]
		v = (int(x.split()[1]) + y) % nz[0]

		if u == 0:
			u = nz[0]

		if v == 0:
			v = nz[0] 

		if str(u) + ' ' + str(v) not in edges:
			if str(v) + ' ' + str(u) not in edges:
				flag = 1
				break
	if flag == 0:
		print("Yes")
		break

if flag == 1:
	print("No")

	
