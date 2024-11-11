from sys import exit

n = int(input())
strings = [input() for _ in range(n)]

strings = sorted(strings, key=len)

for i in range(len(strings) - 1):
	if strings[i] not in strings[i + 1]:
		print('NO')
		exit()

print('YES')
for string in strings:
	print(string)