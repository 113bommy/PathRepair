n = int(input())
top = n // 2
for i in range(top):
	x = top + 2 * i
	print(str(x) + ' 3')
bot = n - top
for i in range(bot):
	print(str(i) + ' 0')