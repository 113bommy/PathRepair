import sys

def solve(x, y):
    ix = 0
    iy = 0
    sum_x = 0
    sum_y = 0
    count = 0

    while ix < len(x) or iy < len(y):
        if sum_x < sum_y:
            sum_x += x[ix]
            ix += 1
        else:
            sum_y += y[iy]
            iy += 1

        if sum_x == sum_y:
            count += 1

    return count


def main():
    line = sys.stdin.readline().split(' ')
    n = int(line[0])
    m = int(line[1])

    x = [int(i) for i in sys.stdin.readline().split(' ')]
    y = [int(i) for i in sys.stdin.readline().split(' ')]

    print(solve(x, y))


if __name__ == '__main__':
    main()
