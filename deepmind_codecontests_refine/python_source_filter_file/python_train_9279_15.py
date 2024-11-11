import math

inp = input().split(' ')
n = int(inp[0])
x = int(inp[1])
y = int(inp[2])

sum = n-1
rem = max(0, x-sum)

add = int(math.sqrt(rem))
if add*add != rem:
	add += 1

if add <= 0 or n-1+add > y or n-1+add*add < x:
	print(-1)
else:
	print(add)
	for i in range(n-1):
		print(1)

