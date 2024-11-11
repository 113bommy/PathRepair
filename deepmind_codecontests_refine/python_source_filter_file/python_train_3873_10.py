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


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


BUFSIZE = 8192
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
rstr = lambda: input().strip()
rstrs = lambda: [str(x) for x in input().split()]
rstr_2d = lambda n: [rstr() for _ in range(n)]
rint = lambda: int(input())
rints = lambda: [int(x) for x in input().split()]
rint_2d = lambda n: [rint() for _ in range(n)]
rints_2d = lambda n: [rints() for _ in range(n)]
ceil1 = lambda a, b: (a + b - 1) // b

for _ in range(rint()):
    n, s, t, mem = rint(), list(rstr()), list(rstr()), [0] * 26

    for i in range(n):
        mem[ord(s[i]) - 97] += 1
        mem[ord(t[i]) - 97] += 1

    if any([x & 1 for x in mem]):
        print('No')
    else:
        print('Yes')
        out = []
        for i in range(n):
            if s[i] != t[i]:
                try:
                    ix = t[i + 1:].index(t[i]) + i + 1
                    s[i], t[ix] = t[ix], s[i]
                    out.append(f'{i + 1} {ix + 1}')
                except:
                    ix = s[i + 1:].index(t[i]) + i + 1
                    s[ix], t[n - 1] = t[n - 1], s[ix]
                    s[i], t[n - 1] = t[n - 1], s[i]
                    out.extend([f'{ix + 1} {n}', f'{i + 1} {n - 1}'])

        print(len(out), *out, sep='\n')
