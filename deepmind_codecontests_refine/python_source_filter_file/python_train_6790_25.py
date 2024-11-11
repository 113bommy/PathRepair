'''input
3
1 11
4 2
191 31415926
'''
t=int(input())
for _ in range(t):
	a,b=[int(x) for x in input().split()]
	x=9
	count=0
	while(x<b):
		count+=a
		x=x*10+9
	print(count)