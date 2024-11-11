n = int(input())
a = 0
b = 0
for i in range(n):
	A,B = map(str,input().split())
	if A>B:
		a += 3
	elif B>A:
		b += 3
	else:
		a += 1
		b += 1
print('%d %d'.(a,b))
