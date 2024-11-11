__author__ = 'Darren'


def solve():
    terminal = [input() for _i in range(3)]
    if (terminal[0][0] == terminal[2][2] and terminal[0][1] == terminal[2][1] and
            terminal[0][2] == terminal[2][0] and terminal[1][0] == terminal[1][2]):
        print('YES')
    else:
        print('NO')


if __name__ == '__main__':
    solve()