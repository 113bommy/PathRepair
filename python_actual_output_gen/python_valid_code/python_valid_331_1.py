n = int(input())
a = []
count = 1
for i in range(n):
	x = str(input())
	a.append(x)
for i in range(7):
	x = ''
	c = 0
	for j in range(n):
		x += a[j][i]
	for k in range(len(x)):
		if x[k] == '1':
			c += 1
	if c > count:
		count = c	
print(count)	
# Sun Sep 15 2019 11:02:12 GMT+0300 (MSK)
