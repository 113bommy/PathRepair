import unittest
import sys


class Tests(unittest.TestCase):
    def test1(self):
        f1 = open("tests/1.txt")
        f2 = open("tests/1a.txt")

        sys.stdin = f1

        self.assertEqual(main(), int(f2.read()), "1st test")

        f1.close()
        f2.close()

        sys.stdin = sys.__stdin__

    def test2(self):
        f1 = open("tests/2.txt")
        f2 = open("tests/2a.txt")

        sys.stdin = f1

        self.assertEqual(main(), int(f2.read()), "2nd test")

        f1.close()
        f2.close()

        sys.stdin = sys.__stdin__

    def test3(self):
        f1 = open("tests/3.txt")
        f2 = open("tests/3a.txt")

        sys.stdin = f1

        self.assertEqual(main(), int(f2.read()), "3rd test")

        f1.close()
        f2.close()

        sys.stdin = sys.__stdin__


def main():
    a = int(input())    # Галстук
    b = int(input())    # Шарф
    c = int(input())    # Жилетка
    d = int(input())    # Пиджак
    e = int(input())
    f = int(input())

    s = 0

    if e >= f:
        s += e * min(a, d)
        d -= min(a, d)
        s += f * min(b, c, d)

    else:
        s += f * min(b, c, d)
        d -= min(b, c, d)
        s += e * min(a, d)

    return s


if __name__ == "__main__":
    main()
