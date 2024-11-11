grid = [list(input()) for _ in range(3)]


def solve(grid):
    flat_grid = [x for lst in grid for x in lst]

    rows = grid[::]
    columns = [grid[i][j] for j in range(3) for i in range(3)]
    diag_1 = [grid[i][2 - i] for i in range(3)]
    diag_2 = [grid[2 - i][i] for i in range(3)]

    trios = rows + columns + [diag_1] + [diag_2]

    Xs = flat_grid.count('X')
    Os = flat_grid.count('0')

    if Os > Xs:
        print('illegal')
        return

    if Xs > Os + 1:
        print('illegal')
        return

    if any(t == ['X']*3 for t in trios) and any(t == ['0']*3 for t in trios):
        print('illegal')
        return

    for s in 'XO':
        if sum(c == [s]*3 for c in columns) > 1:
            print('illegal')
            return
        if sum(r == [s]*3 for r in rows) > 1:
            print('illegal')
            return

    if any(t == ['0']*3 for t in trios) and Xs > Os:
        print('illegal')
        return

    if any(t == ['X']*3 for t in trios) and Xs == Os:
        print('illegal')
        return

    if any(t == ['0']*3 for t in trios):
        print('the second player won')
        return

    if any(t == ['X']*3 for t in trios):
        print('the first player won')
        return

    if all(f != '.' for f in flat_grid):
        print('draw')
        return

    if (Os + Xs) % 2 == 0:
        print('first')
    else:
        print('second')


solve(grid)