n = map(int, input())
s = input()
l = []
cnt = 1
for i in range( 1, len(s)):
	if s[i] != s[i-1]:
		l.append(cnt)
		cnt = 1
	else:
		cnt += 1
l.append(cnt)
result = len(l)
add = 0

if max(l) >= 3:
	add = 2
elif max(l) >= 2:
	add = 1

if len(l) > 1:
	for i in range( 1, len(l)):
		if l[i] >= 2 and l[i-1] >= 2:
			add = 2
	if s[0] != s[len(s)-1] and l[0] >= 2 and l[len(l)-1] >= 2:
		add = 2
	num = 0
	for i in range( 1, len(l)):
		if l[i] >= 2:
			num += 1
	if num >= 2:
		add = 2
if add == 0 and (l[0] >= 2 or l[len(l)-1] >= 2):
	add = 1

print(result + add)
