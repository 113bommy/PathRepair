n = int(input())
l = ''.join(input().split())
l = l.strip('0')
divs = 0
for a, b in zip(l[:-1], l[1:]):
	if a == '1' and b == '0':
		divs += 1
if l.count('1') == 0:
	print(0)
elif l.count('0') == 0:
	print(len(l))
else:
	print(l.count('1') + 2 * divs - 1)
