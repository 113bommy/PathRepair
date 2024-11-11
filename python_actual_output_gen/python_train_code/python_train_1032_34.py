s  = input()
days52 = [1,2,3,4]
s1 = ''
for i in s:
	if i.isdigit() == True:
		s1 += i

if 'week' in s:
	if int(s1) in days52:
		print(52)
	else:
		print(53)

if 'month' in s:
	if int(s1) == 30:
		print(11)
	elif int(s1) == 31:
		print(7)
	else:
		print(12)