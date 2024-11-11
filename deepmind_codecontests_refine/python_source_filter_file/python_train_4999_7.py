from collections import deque

n = int(input())
commands = [input() for _ in range(n)] # splitとかしてると間に合わない

l = deque()
for com in commands:
    if com[0]=='i':
        l.appendleft(com[6:-1])
    elif com[6]=='F':
        l.popleft()
    elif com[6]=='L':
        l.pop()
    else:
        try:
            l.remove(com[7:-1])
        except:
            pass

s = ' '.join(l)
print(s)
