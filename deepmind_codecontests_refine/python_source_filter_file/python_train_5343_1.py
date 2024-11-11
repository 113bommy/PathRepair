import sys

# sys.setrecursionlimit(10**5)
int1 = lambda x: int(x)-1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.buffer.readline())
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def LI1(): return list(map(int1, sys.stdin.buffer.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def LLI1(rows_number): return [LI1() for _ in range(rows_number)]
def BI(): return sys.stdin.buffer.readline().rstrip()
def SI(): return sys.stdin.buffer.readline().rstrip().decode()
# dij = [(0, 1), (-1, 0), (0, -1), (1, 0)]
dij = [(0, 1), (-1, 0), (0, -1), (1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]
inf = 10**16
md = 998244353
# md = 10**9+7

class haha:
    def __init__(self, s=""):
        self.val = self.cnt(s)
        self.pre = s[:3]
        self.suf = s[-3:]
        self.size = len(s)

    def cnt(self, s):
        res = 0
        for i in range(len(s)-3):
            if s[i:i+4] == "haha": res += 1
        return res

    def __add__(self, other):
        if self.size < 6 and other.size < 6:
            s = self.pre if self.size < 4 else self.pre+self.suf[6-self.size:]
            t = other.pre if other.size < 4 else other.pre+other.suf[6-other.size:]
            return haha(s+t)
        res = haha()
        if self.size < 6:
            s = self.pre if self.size < 4 else self.pre+self.suf[6-self.size:]
            res.pre = (s+other.pre)[:3]
            res.suf = other.suf
        elif other.size < 6:
            t = other.pre if other.size < 4 else other.pre+other.suf[6-other.size:]
            res.pre = self.pre
            res.suf = (self.suf+t)[:-3]
        else:
            res.pre = self.pre
            res.suf = other.suf
        res.val = self.cnt(self.suf+other.pre)+self.val+other.val
        res.size = self.size+other.size
        return res

for testcase in range(II()):
    n = II()
    var = {}
    last = ""
    for _ in range(n):
        task = SI().split()
        if task[1] == ":=":
            var[task[0]] = haha(task[2])
        else:
            var[task[0]] = var[task[2]]+var[task[4]]
        last = task[0]
        # print(var)
    print(var[last].val)
