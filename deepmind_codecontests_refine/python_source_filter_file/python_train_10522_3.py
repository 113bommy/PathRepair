while True:
    (m, f, r) = [int(i) for i in input().split()]
    if m == f == r == -1:
        break

    mf = m + f
    
    if m == -1 or f == -1 of mf < 30:
        print('F')
    elif mf < 50 and r < 50:
        print('D')
    elif mf < 65:
        print('C')
    elif mf < 80:
        print('B')
    else:
        print('A')