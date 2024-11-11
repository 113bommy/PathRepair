s = input()
if '.' not in s:
	s = s + '.00'
s = s.strip('0')

if '.' == s[-1]:
	s = s.strip('.')
	if len(s) == 1:
		print(s.strip('.'))
	else:
		exp = len(s)-1
		s = s[0] + '.' + s[1:]		
		s = s.strip('0')
		s = s.strip('.')
		print(s+'E'+str(exp))


#.000567
#5.67e-4
elif '.' == s[0]:
	s = s.strip('.')
	exp = len(s)
	ind = 0
	while s[ind] == '0':
		ind += 1
	exp = ind+1
	if ind == len(s)-1:
		s = s[ind]
	else:
		s = s[ind] + '.' + s[ind+1:]
	s = s + 'E-' + str(exp)
	print(s)

else:
	arr = s.split('.')
	print(arr)
	if len(arr[0]) == 1:
		print(s)
	else:
		exp = len(arr[0])-1
		print(arr[0][0] + '.' + arr[0][1:] + arr[1] + 'E' + str(exp))
