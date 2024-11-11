size = int(input())
s = input()

r = 0

for i in range(size):
	if s[i] == '<':
		r += 1
	else:
		break

for i in range(size - 1, -1, -1):
	if s[i] == '>':
		r += 1
	else:
		break

print(r)