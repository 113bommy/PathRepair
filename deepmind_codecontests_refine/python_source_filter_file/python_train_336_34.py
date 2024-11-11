from sys import stdin


def inp():
    return stdin.buffer.readline().rstrip().decode('utf8')


def itg():
    return int(stdin.buffer.readline())


def mpint():
    return map(int, stdin.buffer.readline().split())


# ############################## import
from bisect import bisect_left, bisect_right

MOD = int(1e9) + 7
LOAD = int(1e6) + 3


class Sequential:
    def __init__(self, data=None):
        if data is None:
            data = [1]
        self.data = data

    def __getitem__(self, item):
        if isinstance(item, slice):
            last = item.stop - 1
        else:
            last = item
        if last > LOAD:
            return self.__call__(item)
        if len(self) <= last:
            self.resize(last + 1)
        return self.data[item]

    def resize(self, n):
        """ resize data to n """
        del self.data[n:]
        length = len(self)
        self.data.extend([None] * (n - length))
        for i in range(length, n):  # modify here if you need the index
            self.data[i] = self.next(self.data[i - 1])

    def resize_with_value(self, value):
        """ extend data until data[-1] >= value"""
        if self.data[-1] < value:
            while True:
                self.data.append(self.next(self.data[-1]))
                if self.data[-1] >= value:
                    return self.data[-1]

    @staticmethod
    def next(a_n):
        return NotImplemented

    def prev(self, a_n):
        return self.lower(a_n)

    def bisect_left(self, value):
        """ return smallest i s.t. a(i) >= value"""
        self.resize_with_value(value)
        return bisect_left(self.data, value)

    def bisect_right(self, value):
        """ return smallest i s.t. a(i) > value"""
        self.resize_with_value(value)
        return bisect_right(self.data, value)

    def ceil(self, value):
        return self.data[self.bisect_left(value)]

    def higher(self, value):
        index = self.bisect_left(value)
        ceil = self.data[index]
        return self[index + 1] if ceil == value else ceil

    def floor(self, value):
        if value < self.data[0]:
            return None
        return self.data[self.bisect_right(value) - 1]

    def lower(self, value):
        index = self.bisect_left(value)
        return None if index == 0 else self.data[index - 1]

    def __len__(self):
        return len(self.data)

    def __call__(self, item):
        return NotImplemented


def A011782(n=None, mod=MOD):
    """
    2^n
    1, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536,

    O(n): a(0)~a(n)
    O(n): a(n)
    O(logn): a(n, mod)
    O(1): a(n+1) (if a(n) is known)

    Cited by
    A059204:
    number of unimodal permutations e.g. 12345 or 54321 or 12543
    permutations like 213 or 312 are not
    and there are 2^(n-1) that is unimodal which n is the number of items
    """
    if n is not None:
        return pow(2, n, mod)

    class Seq(Sequential):
        @staticmethod
        def next(a_n):
            return (a_n << 1) % mod

        @staticmethod
        def __call__(n_, mod_=MOD):  # O(logn)
            return pow(n_, mod_)

    return Seq()


def A000142(n=None, mod=MOD):
    """
    Factorial numbers: n! = 1*2*3*4*...*n
    1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800,

    O(n): a(0)~a(n)
    O(n): a(n)
    O(n): a(n, mod)
    O(1): a(n+1) (if a(n) and n are known)

    Cited by:
    A059204 (number of permutations of n letters)
    """
    if n is not None:
        r = 1
        for i in range(2, n + 1):
            r = r * i % mod
        return r

    class Seq(Sequential):
        def resize(self, n):
            """ resize data to n """
            del self.data[n:]
            length = len(self)
            self.data.extend([None] * (n - length))
            for i in range(length, n):
                self.data[i] = self.data[i - 1] * i % mod

    return Seq()


def A059204(n=None, mod=MOD):
    """
    Number of non-unimodal permutations of n items
    (i.e., those which do not simply go up for the first part
    and then down for the rest, but at some point go down then up).
    e.g. 213 or 312 is non-unimodal
    and 12345 or 54321 or 12543 is unimodal

    0, 0, 0, 2, 16, 104, 688, 4976, 40192, 362624, 3628288, 39915776, 478999552, 6227016704

    O(n): a(0)~a(n)
    O(n): a(n)
    O(n): a(n, mod)
    O(1): a(n+1) (if a(n) and n are known)
    """
    if n is not None:
        return (A000142(n, mod) - A011782(n - 1)) % mod

    class Seq(Sequential):
        def __init__(self):
            self.A000142 = A000142()
            self.A011782 = A011782()
            super().__init__([0, 0, 0, 2])

        def resize(self, n):
            """ resize data to n """
            del self.data[n:]
            self.A000142.resize(n)
            self.A011782.resize(n)
            length = len(self)
            self.data.extend([None] * (n - length))
            for i in range(length, n):  # formula here
                self.data[i] = self.A000142[i] - self.A011782[i - 1]

    return Seq()


# ############################## main
# def main():
# for case in range(1, itg()+1):
print(A059204()[itg()])
# Please check!
