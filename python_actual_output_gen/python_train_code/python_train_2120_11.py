n = int(input())
x,y = map(int,input().split())
k = x+y-2
h= n*n-x-y
if h==k or k<h:
	print('White')
else:
	print('Black')