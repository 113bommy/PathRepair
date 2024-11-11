l = int(input())
stack = [1]
x = 0
mx = 2 ** 32 - 1
for i in range(l):
    cmd = input().split()
    if len(cmd) == 2:
        stack.append(min(int(cmd[1]) * stack[-1], mx))
    elif cmd[0] == 'add':
        x += stack[-1]
    else:
        stack.pop()
if x >= mx:
    print('OVERFLOW!!!')
else:
    print(x)
