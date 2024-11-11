stack = []

for x in input().split():
    if x == '+':
        stack.append(stack.pop()+stack.pop())
    elif x == '-':
        stack.append(stack.pop()-stack.pop())
    elif x == '*':
        stack.append(stack.pop()*stack.pop())
    else:
        stack.append(int(x))

print(stack[0])
