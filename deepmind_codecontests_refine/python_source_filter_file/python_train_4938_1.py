n, v = map(int, input().split())

selected = []
ones = []
twos = []
ans = 0

for i in range(1, n + 1):
	t, p = map(int, input().split())
	if t == 1:
		ones.append((p, i))
	if t == 2:
		twos.append((p, i))

ones.sort()
twos.sort()
num1 = len(ones)
num2 = len(twos)
last_one = None

while num1 + num2 > 0 and v > 0:
	if v == 1:
		if num1 == 0 and last_one is not None:
			p, i = twos[-1]
			if p > last_ans1:
				selected.remove(last_one)
				selected.append(i)
				ans += p - last_ans1
		elif num1 == 0:
			ans += ones[-1][0]
			selected.append(ones[-1][1])
		break
	if num1 == 0:
		num2 -= 1
		p, i = twos.pop()
		v -= 2
	elif num2 == 0:
		num1 -= 1
		p, i = ones.pop()
		v -= 1
	else:
		if 2 * ones[-1][0] > twos[-1][0]:
			num1 -= 1
			p, i = ones.pop()
			v -= 1
			last_one = i
			last_ans1 = p
		else:
			num2 -= 1
			p, i = twos.pop()
			v -= 2
	ans += p
	selected.append(i)

print(ans)

print(' '.join([str(s) for s in selected]))

