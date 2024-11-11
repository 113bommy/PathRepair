#!/user/bin/env/python 3.5
#---*--- code: utf-8 ---*---
def lk(n):
	for i in range(105):
		for j in range(105):
			if 3*i+7*j==n:
				return 1
	return 0

t=int(input())
for k in range(t):
	n=int(input())
	if lk(n):
		print('Yes')
	else:
		print('No')
