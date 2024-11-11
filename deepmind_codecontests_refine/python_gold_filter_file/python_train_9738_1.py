n, k = map(int, input().split())
a = input()
ka = 0
kb = 0
c = 0
answer = 0
for i in range(n):
	if a[i] == "a":
		ka += 1
	else:
		kb += 1
	s = min(ka, kb)
	if k < s:
		if a[c] == "a":
			ka -= 1
		else:
			kb -= 1
		c += 1
	else:
		answer += 1
print(answer)
