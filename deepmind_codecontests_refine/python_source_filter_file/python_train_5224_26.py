# author : sudoer
n = int(input())
a = [i for i in input()]
l = ['0'] * 10
# print (a)
for i in range(n):
	if a[i] == 'L':
		for j in range(0,10):
			if l[j] == '0':
				l[j] = '1'
				break
	elif a[i] == 'R':
		for j in range(9,-1,-1):
			if l[j] == '0':
				l[j] = '1'
				break
	else:
		val  = int(a[i])
		l[val] = '0'

for i in range(10):
	print (l[i] , end = " ")
print ()