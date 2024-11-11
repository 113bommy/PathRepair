from collections import deque
    
n = int(input())
dll = deque()
    
for i in range(n):
    input_line = input().split()
    if input_line[0] == "insert":
        dll.appendleft(input_line[1])
    elif input_line[0] == "delete":
        try:
            dll.remove(input_line[1])
        except:
            pass
    elif input_line[0] == "deleteFirst":
        dll.popleft()
    else:
        dll.pop()
            
print(*dll