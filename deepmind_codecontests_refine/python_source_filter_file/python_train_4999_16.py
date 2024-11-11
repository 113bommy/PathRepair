from collections import deque
n = int(input())
a = deque()
for i in range(n):
    c = input()
    if c == "deleteFirst":
        a.popleft()
    elif c == "deleteLast":
        a.pop()
    else:
        c, v = c.split()
        if c == "insert":
            a.extendleft(v)
        else:
            try:
                a.remove(v)
            except:
                pass
print(" ".join(a))
