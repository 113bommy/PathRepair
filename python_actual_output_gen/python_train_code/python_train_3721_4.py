n = int(input())

colors = input().split()

for i, c in reversed(list(enumerate(colors[1:]))):
	if c != colors[0]:
		from_start = i
		break

for i, c in enumerate(colors[:-1]):
	if c != colors[-1]:
		from_end = len(colors) - (i+1)
		break

print(max([from_start, from_end]))