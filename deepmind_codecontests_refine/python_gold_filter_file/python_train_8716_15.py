n = int(input())
s = []

for i in range(n):
	d = input()
	s.append(d)

z = {"purple":"Power","green":"Time","blue":"Space","orange":"Soul","red":"Reality","yellow":"Mind"}

for i in s:
	if i in z:
		i = z.pop(i)


print(len(z))
for i in z.values():
	print(i)


