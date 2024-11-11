i = [i for i in input().split()]


op = ['+', '*', '-']
stack = []

for j in i:
    if j in op:
        l = stack.pop()
        r = stack.pop()
        stack.append(str(eval(l + j + r)))
    else:
        stack.append(j)

print (stack[0])