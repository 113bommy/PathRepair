def s(n):
	a = 0
	for x in str(n):
		a += int(x)
	return a

n = int(input())

val = s(n)
if val % 4 == 0:
	print(n)
	exit()

#print("val", val)
for x in range(n+1, 1000, 1):
	if s(x) % 4 == 0:
		print(x)
		exit()