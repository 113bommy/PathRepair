n = int(input())
s = input()
a = []
s1, s2 = 0, 0
for i in s:
	if(i == 'z'):
		s1 += 1
	if(i == 'n'):
		s2 += 1
b = []
for i in range(s2):
	b.append('1')
for i in range(s1):
	b.append('0')
print(''.join(b))
		 
		
		
		
