from collections import deque
n = int(input())
d = deque()
for _ in range(n):
    x = input().split()
    if x[0][0] == 'i':
        d.appendleft(int(x[1]))
    elif x[0] == 'delete':
        try:
            d.remove(int(x[1]))
        except ValueError:
            pass
    elif x[0][6] == 'F':
        d.popleft()
    else:
        d.pop()
print(*d)
