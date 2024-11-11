t = int(input())
for _ in range(t):
    s = str(input())

    out = [int(0) for _ in range(3)]
    for move in s:
        if move == 'R':
            out[0] += 1
        elif move == 'P':
            out[1] += 1
        else:
            out[2] += 1

    if out[0] > max(out[1], out[2]):
        print('P'*len(s))
    elif out[1] > max(out[0], out[2]):
        print('S'*len(s))
    else:
        print('R'*len(s))
