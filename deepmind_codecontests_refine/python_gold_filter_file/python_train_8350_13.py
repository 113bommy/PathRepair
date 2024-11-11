n = int(input())
lst = []
for i in range(n):
	lst.append(list(map(int, input().split())))
for i in lst:
	print((23 - i[0]) * 60 + (60 - i[1]))
