def solve(s, a, b):
	cnt = 0
	res = 0
	for ch in s:
		if ch == b:
			res += cnt
		if ch == a:
			cnt += 1
	return res
		
s = input()
res = 0
for i in range(26):
	res = max(res, len([x for x in s if x == chr(i + 96)]))
	for j in range(26):
		res = max(res, solve(s, chr(96 + i), chr(96 + j)))
print(res)



