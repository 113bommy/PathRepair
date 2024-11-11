from sys import stdin


def main():
    s = stdin.readline()
    stack = []
    ok = True
    ans = 0
    close = '>}])'
    open = '<{[('
    for i in range(len(s) - 1):
        if s[i] in close:
            if not stack:
                ok = False
                break
            else:
                i1 = close.index(s[i])
                i2 = open.index(stack[-1])
                if i1 != i2:
                    ans += 1
                stack.pop()
        else:
            stack.append(s[i])
    if stack or not ok:
        print('Impossible')
    else:
        print(ans)


if __name__ == '__main__':
    main()
