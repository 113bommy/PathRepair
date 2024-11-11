# from debug import debug
import sys

t_ = int(input())
while t_:
	t_-=1
	n, x = map(int, input().split())
	s = input().strip()
	o,z = 0, 0
	for i in s:
		if i == '1':
			o+=1
		else:
			z+=1
	maxx = z-o
	bal = ans = 0
	for i in s:
		if maxx == 0:
			if bal == x:
				ans = -1
				break
		else:
			if (x-bal)%maxx == 0 and (x-bal)//maxx >= 0:
				ans += 1
		if i == '0':
			bal += 1
		else:
			bal -= 1
	print(ans)

	