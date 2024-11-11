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
        n, k = self.next_ints()
        x = self.next_ints()
        ss = []
        s = 0
        for a in x[::-1]:
            s += a
            ss.append(s)
        ss = sorted(ss, reverse=True)
        print(s + sum(ss[:k - 1]))


if __name__ == '__main__':
    Main().solve()
