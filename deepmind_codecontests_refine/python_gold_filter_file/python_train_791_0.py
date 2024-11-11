n = int(input())

v = []

integers = []

for i in range(n):
	v.append(list(map(int, input().split())))
#print(v)
for i in v[0]:
	integers.append(i)
	if n > 1:
		for j in v[1]:
			integers.append(j)
			if n > 2:	 				
				for k in v[2]:
					integers.append(k)
					integers.append(i*10 + k)
					integers.append(k*10 + i)
					integers.append(j*10 + k)
					integers.append(k*10 + j)
			integers.append(j*10 + i)
			integers.append(i*10 + j)
integers.sort()
#print(integers)
for i in range(1, 100):
	if not i in integers:
		print(i-1)
		break

