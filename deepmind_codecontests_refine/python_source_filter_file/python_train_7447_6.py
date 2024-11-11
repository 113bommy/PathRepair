n, k, h = map(int, input().split())
a = [int(i) for i in input().split()]

l = 0
t = 0
for c in a:
	if l + c > h:
		tt = (l + c - h) // k
		if (l + c - h) % k != 0:
			tt += 1
		l -= tt * k
		if l < 0:
			l = 0
		t += tt
	l += c

tt = l // k
if l % k != 0:
	tt += 1
t += tt

print(t)
