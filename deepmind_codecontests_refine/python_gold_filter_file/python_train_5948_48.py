n = int(input())
s = input()

j = 0
for i in range(1, n + 1):
	print(s[j], end='')
	j += i
	if (j >= n):
		break