for _ in range(int(input())):
    s = input()
    r = 0
    p = 0
    c = 0
    for ch in s:
        if ch == 'R':
            p += 1
        elif ch == 'P':
            c += 1
        else:
            r += 1
    if p == max([r,p,c]):
        print("P"*len(s))
    elif r == max([r,p,c]):
        print("R"*len(s))
    else:
        print("S"*len(s))
