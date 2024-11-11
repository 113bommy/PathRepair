# -*- coding: utf-8 -*-

from collections import deque

n = int(input())
word = deque()

for i in range(n):
    command = list(map(int, input().split()))
    if command[0] == 0:
        if command[1] == 0:
            word.insert(0, command[1])
        else:
            word.append(command[1])
    elif command[0] == 1:
        print('{0}'.format(word[command[1]]))
    elif command[0] == 2:
        if command[1] == 0:
            word.pop()
        else:
            word.popleft()

