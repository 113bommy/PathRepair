import math
import sys
from collections import defaultdict, Counter
from functools import lru_cache

t = 1
for _ in range(t):
    n = int(input())
    s = input()
    open, closed = 0, 0
    for i in s:
        if i == "(":
            open += 1
        else:
            closed += 1
    if open != closed:
        print(-1)
    else:
        stack = []
        open, closed = 0, 0
        for i in s:
            if i == "(":
                stack.append(i)
                open += 1
            else:
                if len(stack) == 0:
                    stack.append(i)
                    closed += 1
                else:
                    closed += 1
                    if open >= closed:
                        if stack[-1] == "(":
                            stack.pop(-1)
                            open -= 1
                            closed -= 1
                    else:
                        stack.append(i)
        print(len(stack))






