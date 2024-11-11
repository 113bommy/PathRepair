t = int(input())
ans = []

for x in range(t):
	n = int(input())
	x = input()
	a = ""
	b = ""
	k = 0
	for c in range(0,n):
		if x[c] == "2":
			a += "1"
			b += "1"
		elif x[c] == "1":
			a += "1"
			b += "0"
			k = c
			break
		else:
			a += "0"
			b += "0"
			
	if k > 0:
		for c in range(k+1, n):
			if x[c] == "2":
				a += "0"
				b += "2"
			elif x[c] == "1":
				a += "0"
				b += "1"
			else:
				a += "0"
				b += "0"
	ans.append(a)
	ans.append(b)
	
for elem in ans:
	print(elem)
			
