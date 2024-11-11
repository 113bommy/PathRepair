import sys 
# sys.stdin = open('input.txt','r')
n = int(input())
min_sum = 1000001
min_f = 0
for i in range(n+1):
	if n > 4*i and (n-4*i)%7 == 0:

		if min_sum >  i + (n-4*i)//7:
			min_sum = i + (n-4*i)//7
			min_f = i

if min_sum == 1000001:
	print(-1)
else:
	for i in range(min_f):
		print(4,end='')
	for i in range((n-4*min_f)//7):
		print(7,end='')