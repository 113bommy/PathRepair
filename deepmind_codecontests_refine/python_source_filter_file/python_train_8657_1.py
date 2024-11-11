# AC
import copy
import sys
from heapq import heappush, heappop

sys.setrecursionlimit(1000000)


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
        n = self.next_int()
        x = sorted([(i + 1, v) for i, v in enumerate(self.next_ints())], key=lambda y: y[1])
        if len(x) <= 3:
            print(1)
        else:
            xx = copy.deepcopy(x)
            rr = xx.pop(0)[0]
            if self.test(xx):
                print(rr)
            else:
                xx = copy.deepcopy(x)
                rr = xx.pop(1)[0]
                if self.test(xx):
                    print(rr)
                else:
                    i = 0
                    j = 1
                    rr = x[n - 1][0]
                    for k in range(2, n):
                        if x[j][1] * 2 == x[i][1] + x[k][1]:
                            i = j
                            j = k
                        elif rr != x[n - 1][0]:
                            print(-1)
                            return
                        else:
                            rr = x[k][0]
                    print(rr)

    def test(self, xx):
        i = 0
        j = 1
        for k in range(2, len(xx)):
            if xx[j] * 2 != xx[i] + xx[k]:
                return False
            i = j
            j = k
        return True


if __name__ == '__main__':
    Main().solve()
