n, x, y = input().split()
n = int(n)
x = int(x)

num = (input())

#last x digits == y

num_rem = num[len(num) - x:]
#print(num_rem)
ctr = 0
new_y = ''
y = str(10 ** int(y))

for i in range(len(num_rem) - len(y)):
	new_y += '0'

new_y += y
print(new_y)

for i in range(len(new_y)):

	if (new_y[i] != num_rem[i]):
		ctr += 1

print(ctr)