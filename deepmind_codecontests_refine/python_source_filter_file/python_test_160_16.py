debug = False

if debug:
    s = """5
    10 10 6 1 2 8
    10 10 9 9 1 1
    9 8 5 6 2 1
    6 9 2 2 5 8
    2 2 1 1 2 1"""
    input_data = iter(s.split('\n'))
else:
    def func():
        while 1:
            yield input()


    input_data = func()


def get_data():
    n_data = int(next(input_data))
    for _ in range(n_data):
        n, m, cleaner_row, cleaner_column, mud_row, mud_column = map(int, next(input_data).split())
        yield n, m, cleaner_row, cleaner_column, mud_row, mud_column


def solve(n, m, cleaner_row, cleaner_column, mud_row, mud_column, dr=1, dc=1):
    steps = 0
    while cleaner_row != mud_row and cleaner_column != mud_column:
        if not (0 < cleaner_row + dr <= m):
            dr = -dr
        if not (0 < cleaner_column + dc <= n):
            dc = -dc
        cleaner_row = cleaner_row + dr
        cleaner_column = cleaner_column + dc
        steps += 1
    print(steps)


def main():
    for data in get_data():
        solve(*data)


if __name__ == '__main__':
    main()
