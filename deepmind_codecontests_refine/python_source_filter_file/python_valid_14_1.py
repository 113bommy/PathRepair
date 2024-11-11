import os, sys
from io import BytesIO, IOBase


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, 8192))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, 8192))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
inp = lambda dtype: [dtype(x) for x in input().split()]
inp_2d = lambda dtype, n: [dtype(input()) for _ in range(n)]
inp_2ds = lambda dtype, n: [inp(dtype) for _ in range(n)]
inp_enu = lambda dtype: [(i, x) for i, x in enumerate(inp(dtype))]
inp_enus = lambda dtype, n: [[i] + inp(dtype) for i in range(n)]
ceil1 = lambda a, b: (a + b - 1) // b

for _ in range(int(input())):
    n, k = inp(int)
    a, mem, ans = inp(int), [[-1] * (n + 1) for _ in range(n)], float('inf')
    mem[0][0], mem[0][1] = 0, a[0] == 1

    if mem[0][1] >= k:
        ans = n - 1

    for i in range(1, n):
        # mem[i][0] = 0
        for j in range(1, i + 2):
            mem[i][j] = mem[i - 1][j]
            if mem[i - 1][j - 1] != -1:
                mem[i][j] = max(mem[i][j], mem[i - 1][j - 1] + (a[i] == j))

            if mem[i][j] >= k:
                ans = min(n - j, ans)

    print(ans if ans != float('inf') else -1)
