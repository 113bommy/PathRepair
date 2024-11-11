x, y, x0, y0=list(map(int, input().split()))
P={x0, y0}
s=input()
c=1
print(1, end=' ')
for i in range(len(s)-1):

	if s[i] =='L':
		if y0>=2:
			y0-=1
		if (x0, y0) in P: print(0, end=' ')
		else:
			print(1, end=' '); c+=1; P.add((x0, y0))

	elif s[i] =='U':
		if x0>=2:
			x0-=1
		if (x0, y0) in P: print(0, end=' ')
		else:
			print(1, end=' '); c+=1; P.add((x0, y0))

	elif s[i] =='R':
		if y0<y:
			y0+=1
		if (x0, y0) in P: print(0, end=' ')
		else:
			print(1, end=' '); c+=1; P.add((x0, y0))

	elif s[i] =='D':
		if x0<x:
			x0+=1
		if (x0, y0) in P: print(0, end=' ')
		else:
			print(1, end=' '); c+=1; P.add((x0, y0))

print(x*y-c)

