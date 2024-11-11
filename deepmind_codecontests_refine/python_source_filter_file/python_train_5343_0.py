t = int(input())

curvars = {}

def concat(a, b):
	pa, sa, na = a
	pb, sb, nb = b
	x = 0
	for i in range(0, 10):
		if (sa + pb)[i:i + 4] == "haha":
			x += 1
	return (pa + pb)[:3], (sa + sb)[-3:], na + nb + x

for _ in range(t):
	n = int(input())
	for _ in range(n):
		s = input()
		if ":=" in s:
			name, _, val = s.split()
			curvars[name] = (val[:3], val[-3:], val.count("haha"))
		else:
			name, _, a, _, b = s.split()
			curvars[name] = concat(curvars[a], curvars[b])

		print(curvars[name])
