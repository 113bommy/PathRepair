#!/usr/bin/env python3
# 768B_code.py - Codeforces.com/problemset/problem/768/B by Sergey 2017

import unittest
import sys

###############################################################################
# Code Class (Main Program)
###############################################################################


class Code:
    """ Code representation """

    def __init__(self, test_inputs=None):
        """ Default constructor """

        it = iter(test_inputs.split("\n")) if test_inputs else None

        def uinput():
            return next(it) if it else sys.stdin.readline().rstrip()

        # Reading single elements
        [self.n, self.l, self.r] = map(int, uinput().split())

    def bitlist(self, n):
        result = []
        while n > 0:
            result.append(n & 1)
            n = int(n/2)
        result.reverse()
        return result

    def period(self, i):
        return 2 << i

    def start(self, i):
        return (1 << i) - 1

    def count(self, s, p, l, r):
        start = 1 if (l - s) % p == 0 else 0
        return ((r - s) // p) - ((l - s) // p) + start

    def calculate(self):
        """ Main calcualtion function of the class """

        result = 0
        bl = self.bitlist(self.n)
        for (i, n) in enumerate(bl):
            if n == 1:
                period = self.period(i)
                start = self.start(i)
                result += self.count(start, period, self.l+1, self.r+1)

        return str(result)

###############################################################################
# Unit Tests
###############################################################################


class unitTests(unittest.TestCase):

    def test_single_test(self):
        """ Code class testing """

        # Constructor test
        test = "7 2 5"
        d = Code(test)
        self.assertEqual(d.n, 7)
        self.assertEqual(d.l, 2)
        self.assertEqual(d.r, 5)

        # Sample test
        self.assertEqual(Code(test).calculate(), "4")

        # Binlist (big endian) test
        self.assertEqual(d.bitlist(6), [1, 1, 0])
        self.assertEqual(d.bitlist(6)[0], 1)

        # Period test
        self.assertEqual(d.period(0), 2)
        self.assertEqual(d.period(2), 8)

        # Start test
        self.assertEqual(d.start(0), 0)
        self.assertEqual(d.start(3), 7)

        # Count test
        self.assertEqual(d.count(6, 8, 3, 5), 0)
        self.assertEqual(d.count(6, 8, 5, 14), 2)

        # Sample test
        test = "10 3 10"
        self.assertEqual(Code(test).calculate(), "5")

        test = "20000000 0 0"
        self.assertEqual(Code(test).calculate(), "0")

        # Sample test
        test = ""
        # self.assertEqual(Code(test).calculate(), "0")

        # My tests
        test = ""
        # self.assertEqual(Code(test).calculate(), "0")

        # Time limit test
        # self.time_limit_test(5000)

    def time_limit_test(self, nmax):
        """ Timelimit testing """
        import random
        import timeit

        # Random inputs
        test = str(nmax) + " " + str(nmax) + "\n"
        numnums = [str(i) + " " + str(i+1) for i in range(nmax)]
        test += "\n".join(numnums) + "\n"
        nums = [random.randint(1, 10000) for i in range(nmax)]
        test += " ".join(map(str, nums)) + "\n"

        # Run the test
        start = timeit.default_timer()
        d = Code(test)
        calc = timeit.default_timer()
        d.calculate()
        stop = timeit.default_timer()
        print("\nTimelimit Test: " +
              "{0:.3f}s (init {1:.3f}s calc {2:.3f}s)".
              format(stop-start, calc-start, stop-calc))

if __name__ == "__main__":

    # Avoiding recursion limitaions
    sys.setrecursionlimit(100000)

    if sys.argv[-1] == "-ut":
        unittest.main(argv=[" "])

    # Print the result string
    sys.stdout.write(Code().calculate())
