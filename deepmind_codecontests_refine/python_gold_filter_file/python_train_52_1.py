def main():
    eqn = input().split()
    pos_inds = [0]
    neg_inds = []
    n = int(eqn[-1])
    for i, x in enumerate(eqn):
        if x == '+':
            pos_inds.append(i + 1)
        elif x == '-':
            neg_inds.append(i + 1)

    pos = len(pos_inds)
    neg = len(neg_inds)

    val = pos - n * neg
    pos_vals = [1] * pos
    neg_vals = [n] * neg
    ptr = 0
    while ptr < len(pos_vals) and val < n:
        while ptr < len(pos_vals) and pos_vals[ptr] == n:
            ptr += 1

        if ptr == len(pos_vals):
            break

        pos_vals[ptr] += 1
        val += 1

    ptr = 0
    while ptr < len(neg_vals) and val < n:
        while ptr < len(neg_vals) and neg_vals[ptr] == 1:
            ptr += 1
        if ptr == len(neg_vals):
            break

        neg_vals[ptr] -= 1
        val += 1

    if val != n:
        print('Impossible')
    else:
        print('Possible')
        for i, x in enumerate(pos_inds):
            eqn[x] = str(pos_vals[i])

        for i, x in enumerate(neg_inds):
            eqn[x] = str(neg_vals[i])

        print(' '.join(eqn))

main()
