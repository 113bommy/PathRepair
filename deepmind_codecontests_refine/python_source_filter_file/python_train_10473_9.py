m, b = map(int ,input().split())

bananas = 0
x = 0


def f(a):
	global m, b
	return -a/m + b
while (x <= b*m):

	temp = (x+1)*(f(x)+1)*(x+f(x))/2
	bananas = temp if (temp > bananas) else bananas
	
	x += m

print(int(bananas))