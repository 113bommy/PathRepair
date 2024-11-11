n = int(input().strip())
s = input().strip()
ans = 0
ba = 0
if n == 1:
    print(-1)
else:
    stack = []
    stack.append((s[0],0))
    if s[0] == '(':
        ba += 1
    else:
        ba -= 1
        
    for i in range(1,n):
        print(stack)
        if s[i] == ')':
            if stack == [] or stack[-1][0] != '(':
                stack.append((s[i],i))
            else:
                stack.pop()
            ba -= 1

        else:
            stack.append((s[i],i))
            ba += 1

        if ba == 0 and stack != []:
            ans +=(i - stack[0][1]) + 1
            stack = []
            
    if ba != 0:
        print(-1)
    else:
        print(ans)
