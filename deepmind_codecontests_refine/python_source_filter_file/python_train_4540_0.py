from sys import stdin, stdout

n = int(stdin.readline())
used = [0 for i in range(n + 1)]
delete = set()
stack = []
ans = 0
cnt = set()
number = 1
label = 0

for i in range(2 * n):
    s = stdin.readline().strip().split()
    
    while stack and stack[-1] in delete:
        cnt.discard(stack[-1])
        stack.pop()
        
    
    if s[0] == 'add':
        stack.append(int(s[1]))
        
        if label:
            cnt.add(s[1])
            
    else:
        if label and not len(cnt):
            delete.add(number)
        elif stack[-1] == number:
            cnt.discard(stack[-1])
            stack.pop()
        else:
            ans += 1
            cnt = set()
            delete.add(number)
            label = 1
            
        
        number += 1

stdout.write(str(ans))