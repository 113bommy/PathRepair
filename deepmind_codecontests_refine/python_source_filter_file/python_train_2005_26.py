for i in range(int(input())):
    am = int(input())
    a = list(input())
    b = list(input())
    for i in range(am):
        a[i] = bool(int(a[i]))
        b[i] = bool(int(b[i]))
    nums = 0
    out = []
    for i in range(am-1,0,-1):
        if a[i] == b[i]:
            continue
        if a[i] != a[0]:
            nums+=1
            out.append(1)
            a[0] = not a[0]
        nums+=1
        out.append(i+1)
        was = [False]*(i+1)
        for g in range(i+1):
            was[g] = a[g]
        for g in range(i+1):
            a[g] = not was[i-g]

    if a[0] != b[0]:
        nums+=1
        out.append(i)
        a[0] = not a[0]
    print(nums, *out)