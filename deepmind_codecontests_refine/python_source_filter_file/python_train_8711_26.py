n = eval(input())
a = []
b = {'purple':'Power', 'green':'Time', 'blue':'Space', 'orange':'Solu', 'red':'Reality', 'yellow':'Gem'}
for i in range(n):
	a.append(input())
for i in a:
	if i  in b:
		del b[i]
print(len(b))
for i in b:
	print(b[i])
