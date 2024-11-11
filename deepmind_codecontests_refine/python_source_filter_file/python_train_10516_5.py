def calc(stack, s):
	a = stack.pop()
	b = stack.pop()
	if s=='+':
		stack.append(a+b)
	elif s=='-':
		stack.append(a-b)
	elif s=='*':
		stack.append(a*b)

		

S = list(input().split())

stack = []
for s in S:
	if s in ['+', '-', '*']:
		calc(stack, s)
	else:
		stack.append(int(s))

print(stack[0])
