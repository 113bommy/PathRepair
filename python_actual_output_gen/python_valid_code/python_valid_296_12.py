baris = input()
string = baris.split(' ')
n = int(string[0])
t = int(string[1])

baris = input()
string = baris.split(' ')
a = []
for i in range(0, n):
	a.append(int(string[i]))

for i in range(0, n):
	n = n - (86400 - a[i])
	if n <= 0:
		break

print(i+1)