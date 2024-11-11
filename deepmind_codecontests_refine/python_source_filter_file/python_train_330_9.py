t = int(input())
for _ in range(t):
	n = int(input())

	arr = [int(p) for p in input().split()]
	if n < 5:
		print(0,0,0)
		continue
	piv = arr[n//2+1]
	
	q = n//2
	while arr[q] == piv and q >= 0:
		q -= 1
	freq = {}

	for i in range(q+1):
		if arr[i] not in freq:
			freq[arr[i]] = 1
		else:
			freq[arr[i]] += 1
	g, s, b = 0, 0, 0
	for i in freq:
		if g == 0:
			g += freq[i]
		elif s <= g:
			s += freq[i]
		else:
			b += freq[i]
	if not any([g, b, s]) or (g>=b or g>=s):
		print(0,0,0)
	else:
		print(g,s,b)
	

