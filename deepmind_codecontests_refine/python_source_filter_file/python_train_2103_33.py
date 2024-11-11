from math import ceil
t = int(input())
reult = ''
for i in range(t):
	line = input().split(' ')
	a = int(line[0])
	b = int(line[1])
	c = int(line[2])
	d = int(line[3])
	k = int(line[4])

	pen = ceil(a / c)
	pencils = ceil(b / d)

	if pen + pencils <= k:
		result = '{} {}'.format(pen, pencils)
	else:
		result = '-1'

print(result)







		
