ans = []

for t in range(int(input())):
	s = input()
	start, end = float("inf"), -1
	count = 0
	for i in range(len(s)):
		if s[i] == '0': continue
		count += 1
		if i < start: start = i
		elif i > end: end = i
	if count == 0: ans.append('0')
	else: ans.append(str(end - start + 1 - count))

print('\n'.join(ans))