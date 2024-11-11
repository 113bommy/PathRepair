n = int(input())
balls = list(input())
balls.reverse()
stack = []
c = 0
pred = balls[0]
for b in balls:
    if b==pred:
        c += 1
    else:
        stack.append([pred, c])
        c = 1
    pred = b
else:
    stack.append([pred, c])
#print(stack)
cnt = 0
l = len(balls)
while True:
    if stack[-1][0]=='R':
        l -= stack[-1][1]
        stack.pop()
    else:
        k = stack[-1][1]
        cnt += k*(k-1) + 1
        stack.pop()
        if stack:
            stack[-1][1] += k
        else:
            stack.append(['R', k])
        #print("0:", stack)
        #print(cnt)
        continue
    #print("1:", stack)
    if not stack:
        break
    stack[-1][1] -= 1
    if stack[-1][1] == 0:
        stack.pop()
    if not stack:
        stack.append(['R', 1])
    else:
        if stack[-1][0]=='R':
            stack[-1][1] += 1
        else:
            stack.append(['R', 1])
    #print("2:", stack)
    if l < n:
        stack.append(['B', n - l])
    l = n
    #print("3:", stack)
    cnt += 1
    #print(cnt)
print(cnt)

