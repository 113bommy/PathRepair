# region fastio  # from https://codeforces.com/contest/1333/submission/75948789
import sys, io, os

BUFSIZE = 8192


class FastIO(io.IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = io.BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(io.IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
#endregion


Fibs = [1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377,
        610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657,
        46368, 75025, 121393, 196418]
N = int(input())
G_ = [[] for _ in range(N+1)]
for _ in range(N-1):
    u, v = map(int, input().split())
    G_[u].append(v)
    G_[v].append(u)
G = [[] for _ in range(N+1)]
q = [(-1, 1)]

while q:
    p, v = q.pop()
    for u in G_[v]:
        if u != p:
            G[v].append(u)
            q.append((v, u))
Lefts = [0]
U = []
for Gv in G:
    Lefts.append(Lefts[-1]+len(Gv))
    U.extend(Gv)

if N not in Fibs:
    print("NO")
    exit()
idx_Fibs = Fibs.index(N)
Q = [(1, idx_Fibs)]
Counts = [1] * (N+1)
Closed = [False] * (N+1)
while Q:
    V, idx_Fibs = Q.pop()
    if idx_Fibs <= 2:
        continue
    ok1 = Fibs[idx_Fibs-1]
    ok2 = Fibs[idx_Fibs-2]

    q = [V]
    path = []
    while q:
        v = q.pop()
        Counts[v] = 1
        for u in U[Lefts[u]:Lefts[u+1]]:
            if Closed[u]:
                continue
            path.append((v, u))
            q.append(u)
    for v, u in reversed(path):
        if Counts[u] == ok1 or Counts[u] == ok2:
            break
        Counts[v] += Counts[u]
    else:
        print("NO")
        exit()
    Closed[u] = True
    if Counts[u] == ok1:
        Q.append((u, idx_Fibs-1))
        Q.append((V, idx_Fibs-2))
    else:
        Q.append((u, idx_Fibs-2))
        Q.append((V, idx_Fibs-1))
print("YES")
