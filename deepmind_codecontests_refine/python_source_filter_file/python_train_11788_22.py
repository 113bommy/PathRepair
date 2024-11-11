
#start the code from here

t=int(input())
for i in range(t):
	s=input()
	l=[]
	cc=0
	# o=0
	# z=0

	for y in s:
		l.append(y)
	# print(l)
	while len(l)>0 and l[0]=='0':
		l.pop(0)
	while len(l)>0 and l[-1]=='0':
		l.pop(0)
	# print(l)
	cc=l.count('0')
	print(cc)
