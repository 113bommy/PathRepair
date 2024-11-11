n = int(input())

f = [0] * 200
f[0] = 0
f[1] = 2
for k in range(2, 101):
	f[k] = f[k-1] * 2 - 1
for k in range(1, 100):
	if n >= f[k] and n < f[k+1]:
		print(k)
		exit()