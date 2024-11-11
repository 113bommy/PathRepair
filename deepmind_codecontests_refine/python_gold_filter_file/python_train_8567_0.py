import sys

input = sys.stdin.readline

def solve():
	r, c = map(int, input().split())
	r1 = r
	r2 = r
	i = 2
	while True:
		if r2 % i == 0:
			while r2 % i == 0:
				r2 //= i
			while r1 % i == 0:
				#print('r',i)
				if i == 2:
					print('?',r1//i,c,1,1,r1//i+1,1)
					sys.stdout.flush()
					if int(input()) == 0:
						break
					r1 //= 2
				else:
					z = i//2
					h1 = r1//i
					h = h1*z
					print('?',h,c,1,1,h+1,1)
					sys.stdout.flush()
					if int(input()) == 0:
						break
					print('?',h,c,1+h1,1,h+h1+1,1)
					sys.stdout.flush()
					if int(input()) == 0:
						break
					if z != 1:
						print('?',h1,c,1,1,h1+1,1)
						sys.stdout.flush()
						if int(input()) == 0:
							break
					r1 //= i
		if i * i <= r2:
			i += 1
		elif r2 == 1:
			break
		elif i >= r2:
			break
		else:
			i = r2
	i = 2
	c1 = c
	c2 = c
	while True:
		if c2 % i == 0:
			while c2 % i == 0:
				c2 //= i
			while c1 % i == 0:
				#print('c',i)
				if i == 2:
					print('?',r,c1//i,1,1,1,1+c1//i)
					sys.stdout.flush()
					if int(input()) == 0:
						break
					c1 //= 2
				else:
					z = i//2
					w1 = c1//i
					w = w1*z
					print('?',r,w,1,1,1,1+w)
					sys.stdout.flush()
					if int(input()) == 0:
						break
					print('?',r,w,1,1+w1,1,1+w+w1)
					sys.stdout.flush()
					if int(input()) == 0:
						break
					if z != 1:
						print('?',r,w1,1,1,1,1+w1)
						sys.stdout.flush()
						if int(input()) == 0:
							break
					c1 //= i
		if i * i <= c2:
			i += 1
		elif c2 == 1:
			break
		elif i >= c2:
			break
		else:
			i = c2
	r //= r1
	c //= c1
	d1 = 0
	for i in range(1,r+1):
		if r % i == 0:
			d1 += 1
	d2 = 0
	for i in range(1,c+1):
		if c % i == 0:
			d2 += 1
	print('!', d1*d2)

solve()
