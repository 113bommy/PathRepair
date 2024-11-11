'''input
1

'''
s = ['','','']
for i in input().split('+'):
	if i=='1':
		s[0] += '+1' if s[0] else '1'
	elif i=='2':
		s[1] += '+2' if s[1] else '2'
	else:
		s[2] += '+2' if s[2] else '3'


ans = '+'.join([i for i in s if i])
print(ans)
