d1=[x for x in input()]
d2=[x for x in input()]
d3=[x for x in input()]
c=d1+d2+d3
d=[]
for i in range(5):
	if c[i]==c[8-i]:
		d+=['YES']
	else:
		d+=['NO']
if 'NO' in d:
	print('NO')
elif 'NO' not in d:
	print('YES')