def main():
    s = input()
    n, o, c = (s.count(c) for c in '#()')
    o -= c + n - 1
    if o < 0:
        print(-1)
        return
    l = s.split('#')
    b, a = l.pop(), l.pop()
    l.append(''.join((a, ')' * o, b)))
    s = ')'.join(l)
    lvl = 0
    for c in s:
        if c == '(':
            lvl += 1
        elif c == ')':
            lvl -= 1
            if lvl < 0:
                print(-1)
                return
    for i in range(n - 1):
        print(1)
    print(o)


if __name__ == '__main__':
    main()