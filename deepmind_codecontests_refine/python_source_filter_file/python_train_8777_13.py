"""
ID: pranav.27
LANG: PYTHON3
TASK: probname
"""
from functools import lru_cache
import copy
import math
import sys

fin = None
fout = None
uabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
         'W', 'X', 'Y', 'Z']
abet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z']


def start(filename):
    filename = filename.replace('.py', '')
    global fin
    global fout
    infile = filename + ".in"
    outfile = filename + ".out"
    fin = open(infile)
    fout = open(outfile, "w")


def permutation(lst):
    if len(lst) == 0:
        return []
    if len(lst) == 1:
        return [lst]
    l = []
    for i in range(len(lst)):
        m = lst[i]
        remLst = lst[:i] + lst[i + 1:]
        for p in permutation(remLst):
            l.append([m] + p)
    return l


def subsets(x):
    retset = []
    if len(x) == 0:
        retset = [[]]
    else:
        first = x[-1]
        cop = x.copy()
        cop.remove(first)
        y = subsets(cop)
        retset.extend(copy.deepcopy(y))
        m = copy.deepcopy(y)
        for i in range(len(y)):
            k = m[0]
            m.remove(k)
            k.append(first)
            m.append(k)
        retset.extend(m.copy())
    return retset


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return str(self.x) + str(self.y)

    def __hash__(self):
        return hash(str(self))

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y


class frac:
    def __init__(self, n, d):
        self.n = n
        self.d = d

    def __str__(self):
        return str(self.n) + '/' + str(self.d)

    def __hash__(self):
        return hash(str(self))

    def simp(self):
        div = math.gcd(self.n, self.d)
        self.n = self.n / div
        self.d = self.d / div

    def __eq__(self, other):
        return self.n / self.d == other.n / other.d

    def __lt__(self, other):
        return self.n / self.d < other.n / other.d


class Interval:
    def __init__(self, start, end):
        self.start = start
        self.end = end

    def __str__(self):
        return str(self.start) + str(self.end)

    def __hash__(self):
        return hash(str(self))

    def __eq__(self, other):
        return self.start == other.start and self.end == other.end

    def __lt__(self, other):
        return self.start < other.start


class Graph():
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)]
                      for row in range(vertices)]

    def minDistance(self, dist, sptSet):
        min = sys.maxsize
        min_index = -1
        for v in range(self.V):
            if dist[v] < min and sptSet[v] == False:
                min = dist[v]
                min_index = v
        if min_index == -1:
            for v in range(self.V):
                if not sptSet[v]:
                    min_index = v
                    break
        return min_index

    def dijkstra(self, src):
        dist = [sys.maxsize] * self.V
        dist[src] = 0
        sptSet = [False] * self.V
        for cout in range(self.V):
            u = self.minDistance(dist, sptSet)
            sptSet[u] = True
            for v in range(self.V):
                if self.graph[u][v] > 0 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]:
                    dist[v] = dist[u] + self.graph[u][v]

        return dist


def overlap(verl1, verl2):
    if verl1.end >= verl2.start:
        return True
    else:
        return False


def merge(verl1, verl2):
    retverl = Interval(min(verl1.start, verl2.start), max(verl1.end, verl2.end))
    return retverl


def changeBase(num, base):
    if base == 2:
        return "{0:b}".format(num)
    power = math.floor(math.log(num, base))
    remainder = num
    end = []
    iter = list(range(power + 1))
    iter.reverse()
    for i in iter:
        if remainder >= base ** i:
            q, r = divmod(remainder, base ** i)
            end.append(q)
            remainder = r
        else:
            end.append(0)
    retlist = []
    for i in end:
        if i > 9:
            retlist.append(uabet[i - 10])
        else:
            retlist.append(i)
    retlist = map(str, retlist)
    return ''.join(retlist)


def prime(num):
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    for i in range(2, math.ceil(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

def solve(n,a,b):
    if a==1:
        if n%b==1:
            return 'Yes'
        return 'No'
    x = 1
    while x<=n:
        if n%b==x%b:
            return 'Yes'
        x*=a
    return 'No'



def main():
    t = int(input())
    for i in range(t):
        n,a,b = map(int,input().split(' '))
        print(solve(n,a,b))


# code timer

main()
