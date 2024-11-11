n = int(input())

v = [0] * n
pos = 0
for i in range(n ** 2):
	pos += i
	pos %= n
	v[pos] += 1
	
a = "NO"

for i in range(n):
	if v[i] == 0:
		a = "YES"
		break
		
print(a)
