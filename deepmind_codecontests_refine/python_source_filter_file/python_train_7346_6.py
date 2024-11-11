n = int(input())
i = 1
a = []
while(n < i *2):
	n -= i
	a.append(i)
	i += 1
a.append(n)
print(len(a))
print(''.join(map(str, a)))