#!/bin/python

n = int(input())
ans = 0

stack = [1]
accum = [0]

while n:
    n = n - 1
    cmd = input()
    cmd = cmd.split()
    if len(cmd) == 1:
        if cmd[0] == "add":
            accum[-1] = accum[-1] + 1
        else:
            accum[-2] = accum[-2] + accum[-1]*stack[-1]
            if accum[-2] >= 1<<32:
                print("OVERFLOW!!!")
                exit()
            stack.pop()
            accum.pop()
    else:
        accum.append(0)
        stack.append(int(cmd[1]))

ans = accum[-1]*stack[-1]

if ans < 1<<32 - 1:
    print(ans)
else:
    print("OVERFLOW!!!")
