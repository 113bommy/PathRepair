n, mod = map(int, input().split())
s = input()

total = 0
if mod == 2 or mod == 5:
	for i, q in enumerate(s):
		if int(q)%mod == 0:
			total += i+1
else:
	counts = [0]*mod
	counts[0] = 1
	h = 0
	
	d = 1
	for t in reversed(s):
		m = int(s)*d%mod
		h = (h+m)%mod
		total += counts[h]
		counts[h] += 1
		d = (d*10)%mod

print(total)