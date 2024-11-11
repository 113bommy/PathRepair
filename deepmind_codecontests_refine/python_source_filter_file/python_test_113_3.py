from sys import stdin, stdout


def solve():
    x1, p1 = map(int, stdin.readline().strip().split())
    x2, p2 = map(int, stdin.readline().strip().split())
    p = min(p1, p2)
    p1 = p1 - p
    p2 = p2 - p
    if p1 > p2: return('>')
    elif p2 > p1: return('<')
    else:
        y1 = x1 * pow(10, p1)
        y2 = x2 * pow(10, p2)

        if y1 < y2:
            return('<')
        elif y1 > y2:
            return('>')
        else:
            return('=')


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        print(solve())