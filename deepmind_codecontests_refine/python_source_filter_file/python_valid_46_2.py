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


class dict(dict):
    def __missing__(self, key):
        return 0


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
inp = lambda dtype: [dtype(x) for x in input().split()]
inp_2d = lambda dtype, n: [dtype(input()) for _ in range(n)]
inp_2ds = lambda dtype, n: [inp(dtype) for _ in range(n)]
inp_enu = lambda dtype: [(i, x) for i, x in enumerate(inp(dtype))]
inp_enus = lambda dtype, n: [[i] + [inp(dtype)] for i in range(n)]
ceil1 = lambda a, b: (a + b - 1) // b

n, a, ans = int(input()), inp(int), 0

for i in range(1, n, 2):
    if a[i] <= a[i - 1]:
        ext = a[i - 1] - a[i]
        cnt, l, r = 1, 0, 0

        for j in range(i + 2, n, 2):
            l += a[j - 1]
            r += a[j]

            if l < r:
                cnt += 1
                if r - l < ext:
                    break

                ans += cnt - 1
                ext -= r - l
                cnt = 0

            elif l > r:
                continue

            cnt += 1
            l = r = 0

        ans += (cnt - 1)

l, r = 0, 0
for i in range(1, n, 2):
    l += a[i - 1]
    r += a[i]
    d = min(l, r)

    l -= d
    r -= d
    ans += d

    if l < r:
        r = l = 0

print(ans)
