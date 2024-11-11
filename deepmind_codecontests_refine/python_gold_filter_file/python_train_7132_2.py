s = input()
open_b = ["<","{","[","("]
close_b = [">","}","]",")"]
stack = []
d = {open_b[i]:close_b[i] for i in range(4)}
stack = []
ans = 0
for i in range(len(s)):

	stack.append(s[i])
	if len(stack) >= 2 and stack[-1] in close_b and stack[-2] in open_b:
		if d[stack[-2]] != stack[-1]:
			ans = ans + 1
		stack.pop()
		stack.pop()

if len(stack):
	print("Impossible")
	exit()
print(ans)