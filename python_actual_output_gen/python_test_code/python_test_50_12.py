for j in range(int(input())):
    w=0
    z = input()
    a = []
    b = 1
   ##################
    for j in z:
        if j == 'L':
            b += 1
        else:
            if b:
                a.append(b)
            c = 1
    if b:
        a.append(b)
    print(max(a))