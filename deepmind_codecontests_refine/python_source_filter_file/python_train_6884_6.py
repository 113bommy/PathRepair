def main():
    s = input()
    count = 0
    stack = []
    n = len(s)
    for i in range(n):
        if s[i] == '[':
            stack.append(i)
            break

    if not stack:
        print(-1)
        return

    index = stack[-1]
    for i in range(index+1,n):
        if s[i] == ':':
            stack.append(i)
            break

    if len(stack) < 2:
        print(-1)
        return

    index = stack[-1]
    for i in range(n-1,index,-1):
        if s[i] == ']':
            stack.append(i)
            break

    if len(stack) < 3:
        print(-1)
        return

    index = stack[-1]
    for i in range(index-1,stack[-2],-1):
        if s[i] == ':':
            stack.append(i)
            break

    if len(stack) < 4:
        print(-1)
        return
    stack[2],stack[3] = stack[3],stack[2]
    ans = 0
    for i in range(stack[2]+1,stack[3]):
        if s[i] == '|':
            ans += 1

    print(ans+4)

main()
