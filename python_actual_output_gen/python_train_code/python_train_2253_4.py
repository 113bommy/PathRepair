import sys
l = [k.strip() for k in sys.stdin]
m = max(len(a) for a in l)
f = 0
print((m+2)*'*')
for i in range(len(l)):
	a = (m-len(l[i]))//2
	b = a
	if len(l)%2 != m%2:
		if f == 0:
			b+=1
			f = 1
		elif f == 1:
			a+=1
			f = 0
	print('*'+' '*a+l[i]+' '*b+'*')
print((m+2)*'*')
