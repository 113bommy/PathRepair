for _ in range(int(input())):
    s = ''
    lst = []
    for _ in range(int(input())):
        n = input()
        if n == '1':
            lst.insert(0, n)
        else:
            f = lst.index(str(int(n)-1))
            lst = lst[f:]
            lst[0] = n
        print('.'.join(lst[::-1]))