n = int(input())
t = [0, 0]
t += list(map(int, input().split()))
n += 1
a = [0] * n
b = [0] * n
n -= 1
a[1] = b[1] = -1

#print(t, a, b)

def calc(s, a, b, l):
	global t
	l.reverse()
	j = 0
	n = len(l)
	
	while True:
		s += t[l[j]]
		a[l[j]] = s
		j += 1
		if j == n:
			return
		
		s += t[l[j]]
		b[l[j]] = s
		j += 1
		if j == n:
			return

			
def calc2(i, k):
	global a, b
	l = []
	if k:
		a[i] = -1
		l.append(i)
		i += t[i]
		
	while True:
		if i > n:
			return calc(0, a, b, l)
		if b[i] > 0:
			return calc(b[i], a, b, l)
		if b[i] == -1:
			return
		b[i] = -1
		l.append(i)
		i -= t[i]
		if i < 1:
			return calc(0, b, a, l)
		if a[i] > 0:
			return calc(a[i], a, b, l)
		if a[i] == -1:
			return
		a[i] -= 1
		l.append(i)
		i += t[i]

for i in range(2, n + 1):
	if a[i] == 0:
		calc2(i, True)
	if b[i] == 0:
		calc2(i, False)

for i in range(1, n):
	if b[i + 1] > 0:
		t[i] = i + b[i + 1]
	else:
		t[i] = -1

#print(t, a, b)
		
print('\n'.join(map(str, t[1:n])))