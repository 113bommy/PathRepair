ope = {"+": lambda a, b: b + a,
	   "-": lambda a, b: b - a,
	   "*": lambda a, b: b * abs}
stack = []

for c in input().split():
	if c in ope:
		stack.append(ope[c](stack.pop(), stack.pop()))
	else:
		stack.append(int(c))

print(stack[-1])