str = input().strip()

stack = []

i = 1
size = len(str)
stack.append(str[0])

while i < size:

    stack.append(str[i])
    if len(stack) > 1 and stack[-1] == stack[-2]:
        stack.pop()
        stack.pop()

    i += 1

print(stack)

ans = False
if len(stack) == 0:
    ans = True

elif len(stack) == 2:
    if stack[0] == stack[1]:
        ans = True

if ans:
    print("Yes")
else:
    print("No")
