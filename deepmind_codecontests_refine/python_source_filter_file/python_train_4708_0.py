for _ in range(int(input())):
    input()
    l = [int(x) for x in input().split()]
    ec = 0
    oc = 0
    s = 0
    for x in l:
        s += 1
        if x % 2:
            oc += 1
        else:
            ec += 1

    if s % 2 == 1 or  (oc>0 and ec>0):
        print('YES')
    else:
        print('NO')