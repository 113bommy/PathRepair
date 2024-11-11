from collections import deque

n = int(input())
q = deque()

for i in range(n):
    command = input()
    if command[0] == 'i':
        q.appendleft(command[7])
    elif command[6] == ' ':
        try:
            q.remove(command[7])
        except Exception as e:
            pass
    elif command[6] == 'F':
        q.popleft()
    else:
        q.pop()

print(' '.join(q))