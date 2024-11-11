m, n = [int(i) for i in input().split()]
v = m % 2
w = n % 2

if v == 0 and w == 0:
	s = m * (n // 2)
elif v == 0:
	s = m * (n // 2) + m // 2 
elif w == 0:
	s = n * (m // 2) + n // 2 
else:
	s = (m // 2) * (n // 2) + n // 2 + m // 2
print(s)	
