t = int(input())

def gdig(num):
	d = []
	if num<10:
		d.append(num)
	else:
		d=gdig(num//10)
		d.append(num%10)
	return d
for k in range(t):
	n = int(input())
	x = int(input())
	digits = []

	digits = gdig(x)
	

	b=False
	r=False
	if n%2 == 0:
		for i in range(len(digits)):
			if i%2 != 0 and digits[i]%2 == 0:
				b=True
		if not b:
			r = True

	else:
		for i in range(len(digits)):
			if i%2 ==0 and digits[i]%2 != 0:
				r = True
		
		if not r:
			b = True

	if b:
		print(2)
	if r:
		print(1)
