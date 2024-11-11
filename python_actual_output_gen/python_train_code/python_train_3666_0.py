x = input()

a = 0;
b = 0;

sc = x.lstrip('0')
if '.' not in sc:
	sc += '.'

if sc[0] == '.':
	sc = '0' + sc
if sc[-1] == '.':
	sc = sc + '0'

if sc[0] == '0':
	sc.replace('.', '')
	i = 0;
	while sc[i] == '0':
		i += 1
		b -= 1

	sc = sc[i] + '.' + sc[i + 1:]

if ('.' not in sc) and (len(sc) > 1):
	sc = sc[0] + '.' + sc[1:]
	b += 1

b += ( sc.find('.') - 1)

sc = sc.replace('.', '')
a = sc[0] + '.' + sc[1:]

a = a.strip('0')

if a[-1] == '.':
	a = a[:-1]


sc = a + ( '' if (b == 0) else ('E'+str(b)) )
print(sc)
