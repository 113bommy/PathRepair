import sys
import os
from io import IOBase, BytesIO
# import heapq
import math
# import collections
# import itertools
# import bisect
mod = 10 ** 9 + 7
pie = 3.1415926536
# import resource
# resource.setrlimit(resource.RLIMIT_STACK, [0x100000000, resource.RLIM_INFINITY])
# import threading
# threading.stack_size(2**27)
# import sys
# sys.setrecursionlimit(10**6)
# fact=[1]
# for i in range(1,1000001):
#    fact.append((fact[-1]*i)%mod)
# ifact=[0]*1000001
# ifact[1000000]=pow(fact[1000000],mod-2,mod)
# for i in range(1000000,0,-1):
#    ifact[i-1]=(i*ifact[i])%mod
# from random import randint as rn
# from Queue import Queue as Q


def modinv(n, p):
    return pow(n, p-2, p)


def ncr(n, r, p):  # for using this uncomment the lines calculating fact and ifact
    t = ((fact[n])*((ifact[r]*ifact[n-r]) % p)) % p
    return t


def ain():  # takes array as input
    return list(map(int, sin().split()))


def sin():
    return input().strip()


def GCD(x, y):
    while(y):
        x, y = y, x % y
    return x


def read2DIntArray(row, col):
    arr = []
    for i in range(0, row):
        temp = list(map(int, sin().split()))
        arr.append(temp)

    return arr


def read2DCharArray(row, col):
    arr = []
    for i in range(0, row):
        temp = str(sin())
        arr.append(temp)

    return arr


"""****************** SMALLEST NO. BY REARRANGING DIGITS OF n (WITHOUT TRAILING ZEROS) *********************"""


def smallestNumber(n):
    lst = list(str(n))
    lst.sort()

    tmp = ""
    for i, n in enumerate(lst):
        if (n != '0'):
            tmp = lst.pop(i)
            break

    return str(tmp) + ''.join(lst)


"""*********************** GENERATE ALL PRIME NUMBERS SMALLER THAN OR EQUAL TO n ***************************"""


def SieveOfEratosthenes(n):

    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):

        if (prime[p] == True):
            for i in range(p * 2, n + 1, p):
                prime[i] = False

        p += 1
    prime[0] = False
    prime[1] = False

    lst = []
    for p in range(n + 1):
        if prime[p]:
            lst.append(p)

    return lst


"""*************************************** FIND nCr ********************************************************"""


def nCr(n, r):
    a = 1
    b = 1
    c = 1
    for i in range(1, n + 1):
        c *= i
    for i in range(1, r + 1):
        b *= i
    for i in range(1, n - r + 1):
        a *= i

    return (c // (a * b))


"""************************* GET PRIME FACTORS AND THEIR POWERS FOR AN INTEGER *****************************"""


def sieveOfEratosthenes1(N, s):

    prime = [False] * (N+1)

    for i in range(2, N+1, 2):
        s[i] = 2

    for i in range(3, N+1, 2):
        if (prime[i] == False):

            s[i] = i

            for j in range(i, int(N / i) + 1, 2):
                if (prime[i*j] == False):
                    prime[i*j] = True

                    s[i * j] = i


def generatePrimeFactors(N):

    s = [0] * (N+1)

    sieveOfEratosthenes1(N, s)

    # print("Factor Power")

    curr = s[N]

    cnt = 1

    factors = []
    power = []
    while (N > 1):
        N //= s[N]

        if (curr == s[N]):
            cnt += 1
            continue

        # curr is factor and cnt in the power of this factor
        factors.append(curr)
        power.append(cnt)

        curr = s[N]
        cnt = 1

    return factors, power


"""----------------------------------------------MAIN------------------------------------------------------"""


def main():
    n, m, d = map(int, sin().split())
    c = ain()
    summ = sum(c)

    tmp = c.copy()
    lst = []
    res = [0] * n
    pos = 0
    t = 0

    while pos < n + 1 and t < m:
        flag = 0
        for i in range(pos + 1, pos + d+1):
            pos = i
            if pos + summ == n + 1:
                flag = 1
                break

        if flag == 0:
            for i in range(pos, pos+c[t]):
                res[i - 1] = t + 1
            pos += c[t] - 1
            summ -= c[t]
            t += 1

        else:
            for i in range(t, m):
                for j in range(pos, pos + c[i]):
                    res[j - 1] = i + 1
                pos += c[i]

            break

    if pos + d < n + 1:
        print("NO")
    else:
        print("YES")
        print(*res)


"""--------------------------------------------------------------------------------------------------------"""

# Python 2 and 3 footer by Pajenegod and j1729
py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange


BUFSIZE = 8192


class FastIO(BytesIO):
    newlines = 0

    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None

    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0, 2),
                   super(FastIO, self).write(s))[0])
        return s

    def read(self):
        while self._fill():
            pass
        return super(FastIO, self).read()

    def readline(self):
        while self.newlines == 0:
            s = self._fill()
            self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        if py2:
            self.write = self.buffer.write
            self.read = self.buffer.read
            self.readline = self.buffer.readline
        else:
            self.write = lambda s: self.buffer.write(s.encode('ascii'))
            self.read = lambda: self.buffer.read().decode('ascii')
            self.readline = lambda: self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)


def input(): return sys.stdin.readline().rstrip('\r\n')


if __name__ == '__main__':
    main()
# threading.Thread(target=main).start()
