yakoo, wakko = map(int, input().split())

win = max(yakoo, wakko)

res = 7 - win

if res == 1:
	print('0/1')
elif res == 6:
	print('1/1')
else:
	if res % 2 == 0:
		print(f"{res // 2}/3")
	elif res % 3 == 0:
		print(f"{res // 3}/2")
	else:
		print(f"{res}/6")