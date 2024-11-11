c = sorted((int(input()), i + 1) for i in range(int(input())))
if c[0][0] == c[-1][0]:
    print('Exemplary pages.')
elif (c[0][0] + c[-1][0]) % 2:
    print('Unrecoverable configuration.')
else:
    a = (c[0][0] + c[-1][0]) // 2
    if len(c) > 2 and (a != c[1][0] or a != c[-2][0]):
        print('Unrecoverable configuration.')
    else:
        print(a - c[0][0], ' ml. from cup #', c[0][1], ' to cup #', c[-1][1], sep='')
