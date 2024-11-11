
 
for _ in range(int(input())):
	n = int(input())
	a, b, ans = [], [], []
	for i in input()[:-1]:
		if i == '0':
			if b:
				a.append(b.pop())
			else:
				a.append(len(a) + len(b) + 1)
			ans.append(a[-1])
		else:
			if a:
				b.append(a.pop())
			else:
				b.append(len(a) + len(b) + 1)
			ans.append(b[-1])

	print(max(ans))
	print(*ans)