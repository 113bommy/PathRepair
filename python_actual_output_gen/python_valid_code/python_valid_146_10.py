x = int(input())
l = []
for i in range(1,101):
	if  i >= x:
		break
	t = x-i
	s = t

	while t:

		r = t%(10)
		t = t//10
		s = s + r
	
	if s == x:

		l.append(x-i)
print(len(l)) 
for i in l:
	print(i)