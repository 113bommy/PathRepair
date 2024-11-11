s = input()
a, b = s.split('+')
b, c = b.split('=')
a_num = a.count('|')
b_num = b.count('|')
c_num = c.count('|')
if a_num + b_num == c_num + 2 or a_num + b_num + 2 == c_num or a_num + b_num == c_num:
	if a_num + b_num == c_num + 2 and (a_num > 1 or b_num > 1):
		if a_num > 1:
			a_num -= 1
			c_num += 1
			a = '|' * a_num
			c = '|' * c_num
			print(a + '+' + b + '=' + c)
		elif b_num > 1:
			b_num -= 1
			c_num += 1
			b = '|' * a_num
			c = '|' * c_num
			print(a + '+' + b + '=' + c)
		else:
			print('Impossible')
	elif a_num + b_num + 2 == c_num:
		a_num += 1
		c_num -= 1
		a = '|' * a_num
		c = '|' * c_num
		print(a + '+' + b + '=' + c)
	else:
		print(s)
else:
	print('Impossible')