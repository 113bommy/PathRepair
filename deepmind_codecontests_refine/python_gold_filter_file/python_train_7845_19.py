n = int(input())
sudut = []
for i in range (1,500):
	a = (180 * i) / (i+2)
	sudut.append(a)
for i in range (n):
	b = int(input())
	if(b in sudut):
		print ('YES')
	else:
		print ('NO')
