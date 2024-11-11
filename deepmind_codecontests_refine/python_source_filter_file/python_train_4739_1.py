def main():
    n = lie()
    g = []
    for i in range(n - 1):
        g.append(list(liee()))
    temp = cs(n, g)
    print(temp.find())


class cs():
    def __init__(self, n, g):
        self.n = n
        self.edge = defaultdict(list)
        self.sum = 0
        self.dp = vector(n + 1)

        for u, v, w in g:
            self.edge[u].append([v, w])
            self.edge[v].append([u, w])
            self.sum += w

    def dfs(self, ch, par, dis):
        self.dp[ch] = dis
        for v, w in self.edge[ch]:
            if v != par:
                self.dfs(v, ch, dis + w)

    def find(self):
        self.dfs(1, 0, 0)
        dis = max(self.dp)
        return 2 * self.sum - dis


from sys import *
import inspect
import re
from math import *
import threading
from collections import *
from pprint import pprint as pp
mod = 998244353
MAX = 10**5


def lie():
    return int(input())


def liee():
    return map(int, input().split())


def array():
    return list(map(int, input().split()))


def deb(p):
    for line in inspect.getframeinfo(inspect.currentframe().f_back)[3]:
        m = re.search(r'\bdeb\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)', line)
        print('%s %s' % (m.group(1), str(p)))


def vec(size, val=0):
    vec = [val for i in range(size)]
    return vec


def mat(rowNum, colNum, val=0):
    mat = []
    for i in range(rowNum):
        collumn = [val for j in range(colNum)]
        mat.append(collumn)
    return mat


def dmain():
    setrecursionlimit(100000000)
    threading.stack_size(40960000)
    thread = threading.Thread(target=main)
    thread.start()


if __name__ == '__main__':
    # main()
    dmain()
