# AC
import sys


class Main:
    def __init__(self):
        self.buff = None
        self.index = 0

    def next(self):
        if self.buff is None or self.index == len(self.buff):
            self.buff = self.next_line()
            self.index = 0
        val = self.buff[self.index]
        self.index += 1
        return val

    def next_line(self):
        return sys.stdin.readline().split()

    def next_ints(self):
        return [int(x) for x in sys.stdin.readline().split()]

    def next_int(self):
        return int(self.next())

    def solve(self):
        n, m = self.next_ints()
        a = [self.next_ints() for _ in range(0, n)]
        b = [self.next_ints() for _ in range(0, n)]
        c = [[min(a[i][j], b[i][j]) for j in range(0, m)] for i in range(0, n)]
        d = [[max(a[i][j], b[i][j]) for j in range(0, m)] for i in range(0, n)]
        for i in range(0, n):
            for j in range(0, m):
                if i > 0 and c[i][j] <= c[i - 1][j]:
                    print('Impossible')
                    return
                if i > 0 and d[i][j] <= d[i - 1][j]:
                    print('Impossible')
                    return
                if j > 0 and c[i][j] <= c[i][j - 1]:
                    print('Impossible')
                    return
                if j > 0 and d[i][j] <= d[i][j - 1]:
                    print('Impossible')
                    return
        print('Possible')


if __name__ == '__main__':
    Main().solve()
