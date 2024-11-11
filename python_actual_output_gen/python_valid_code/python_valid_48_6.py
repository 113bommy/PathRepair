def r():
    return map(int,input().split())

def ternary(n):
    if n == 0:
        return '0'
    nums = []
    while n:
        n, r = divmod(n, 3)
        nums.append(str(r))
    return ''.join(reversed(nums))

t = int(input())
for _ in range(t):
	n = int(input())
	y = ternary(n)
	if '2' in y:
		val = '1' * len(y)
		if int(val, 3) < n:
			print(3**len(y))
		else:
			v = list(val)
			for i in range(1, len(val)):
				temp = list(v)
				temp[i] = '0'
				if int(''.join(temp), 3) >= n:
					v = list(temp)
			print(''.join(v), 3)
	else:
		print(n)