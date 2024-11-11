s = input()
l = list(s)
a = 'abcdefghijklmnopqrstuvwxyz'
for i in range(len(s)+1):
	for j in a:
		l.insert(i, j)
		print(len(l)-2*len(s))