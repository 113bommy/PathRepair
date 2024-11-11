x = int(input())
a = 0
one = x + 1
two = x + 1
if x % 4 == 1:
	print(0, 'A')
elif one % 4 == 1:
	print(1, 'A')
elif two % 4 == 1:
	print(2, 'A')
elif x % 4 == 3:
	print(0, 'B')
elif one % 4 == 3:
	print(1, 'B')
elif two % 4 == 3:
	print(2, 'B')
elif x % 4 == 2:
	print(0, 'C')
elif one % 4 == 2:
	print(1, 'C')
elif two % 4 == 2:
	print(2, 'C')
elif x % 4 == 0:
	print(0, 'D')
elif one % 4 == 0:
	print(1, 'D')
elif two % 4 == 0:
	print(2, 'D')