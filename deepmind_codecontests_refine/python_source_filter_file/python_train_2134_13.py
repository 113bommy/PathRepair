#!/usr/bin/env python
# -*- coding: utf-8 -*-



def solve(b, p1, p2) -> bool:
    '''
    b:  (int, int)
    p1: (int, int)
    p2: (int, int)
    '''
    large = max(b)
    small = min(b)
    min_p1 = min(p1)
    min_p2 = min(p2)
    max_p1 = max(p1)
    max_p2 = max(p2)
    if min_p1 + min_p2 <= small and max(max_p1, max_p2) <= large:
        return True
    elif max(max_p1, min_p2) <= small and min_p1 + max_p2 <= large:
        return True
    elif max(max_p2, min_p1) <= small and min_p2 + max_p1 <= large:
        return True
    elif max(min_p1, min_p2) <= small and max_p1 + max_p2 <= large:
        return True
    elif max(max_p1, max_p2) <= small and min_p1 + min_p2 <= large:
        return True
    else:
        return False


def getinput():
    def getints_line():
        return list(map(int, input().split(' ')))
    b  = getints_line()
    p1 = getints_line()
    p2 = getints_line()
    return b, p1, p2


def test():
    art = Assert()
    art.equal(solve((3, 2), (1, 3), (2, 1)), True)
    art.equal(solve((5, 5), (3, 3), (3, 3)), False)
    art.equal(solve((4, 2), (2, 3), (1, 2)), True)
    art.equal(solve((2, 9), (5, 1), (3, 2)), True)


def main():
    test()
    # print('YES' if solve(*getinput()) else 'NO')
    # print('\n'.join(map(str, solve(*getinput()))))


import unittest
class Assert(unittest.TestCase):
    def equal(self, a, b):
        self.assertEqual(a, b)

if __name__ == '__main__':
    main()

