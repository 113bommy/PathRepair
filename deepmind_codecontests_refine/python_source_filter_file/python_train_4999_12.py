from collections import deque
n = int(input())

Q = deque()
for i in range(n):
    command = input().split()
    if command[0] == "insert":
        Q.appendleft(command[1])
    elif command[0] == "deleteFirst":
        Q.popleft()
    elif command[0] == "deleteLast":
        Q.popright()
    elif command[0] == "delete":
        try:
            Q.remove(command[1])
        except:
            pass
print(" ".join(Q))