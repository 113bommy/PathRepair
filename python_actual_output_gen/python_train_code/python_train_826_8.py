def generated_from(num):
	yield num
	while num != 0:
		if num % 10 == 1:
			num //= 10
			yield num
		elif num % 2 == 0:
			num //= 2
			yield num
		else:
			break


[a, b] = input().split()
a, b = int(a), int(b)

can_generate_b = list(generated_from(b))
if a in can_generate_b:
	i = can_generate_b.index(a)
	steps = can_generate_b[:i + 1]
	steps.reverse()
	print('YES')
	print(len(steps))
	print(steps)
else:
	print('NO')
