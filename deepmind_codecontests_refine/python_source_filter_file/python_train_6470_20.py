n = int(input())
s = input()
a = [int(x) for x in s]

turn = 0
count = 0
v = []
p = []
for x in range(n):
	if a[x] != 8:
		v += [x]
	else:
		p += [x]

# print(p)
# print(v)

x = p[:]
y = v[:]
p += y
v += x

vind = 0
pind = 0
while count != n-11:
	if turn == 0:
		while a[v[vind]] == -1:
			vind += 1
		a[v[vind]] = -1
		vind += 1

	else:
		while a[p[pind]] == -1:
			pind += 1
		a[p[pind]] = -1
		pind += 1

	if turn == 0:
		turn = 1
	else:
		turn = 0

	count += 1
	# print(a)

for x in a:
	if x != -1 and x != 8:
		win = p
		break

	if x == 8:
		win = v
		break

if win == p:
	print("NO")
else:
	print("YES")
		