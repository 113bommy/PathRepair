string = input()
s      = []
c      = 0
for i in range(len(string)):
	if s and s[-1] == string[i]:
		s.pop()
		c+=1
	else:
		s.append(string[i])
if c&1:print('Yes')
else:print('No')