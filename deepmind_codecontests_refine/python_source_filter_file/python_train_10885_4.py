import array, bisect, collections, copy, fractions, functools, heapq, itertools, math, random, re, string, sys, time, os
from decimal import Decimal

sys.setrecursionlimit(10000000)
inf = float('inf')


def li(): return [int(x) for x in sys.stdin.readline().split()]
def li_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def lf(): return [float(x) for x in sys.stdin.readline().split()]
def ls(): return sys.stdin.readline().split()
def int_inp(): return int(sys.stdin.readline())
def float_inp(): return float(sys.stdin.readline())
def inp(): return sys.stdin.readline().strip()
def pf(s): return print(s, flush=True)


def main():
    if os.path.exists('input.txt'):
        sys.stdin = open('input.txt', 'r')
    # --------------------------------INPUT----------------------------------
    s = inp()
    sums = []
    x = ''
    for i in s:
        if i.isalpha() and x:
            sums.append(x)
            x = ''
        elif i.isdigit() or i == '.':
            x += i
    sums.append(x)
    for i in range(len(sums)):
        sums[i] = sums[i].split('.')
        if len(sums[i][-1]) == 2:
            sums[i] = int(''.join(sums[i][:-1])) + float(f'0.{sums[i][-1]}')
        else:
            sums[i] = int(''.join(sums[i]))
    ans = sum(sums)
    if type(ans) == int or ans % 1 == 0:
        ans = list(str(int(ans)))
        for i in range(len(ans) - 3, 0, -3):
            ans.insert(i, '.')
        ans = ''.join(ans)
    else:
        ans = list(str(ans))
        for i in range(len(ans) - 6, 0, -3):
            ans.insert(i, '.')
        ans = ''.join(ans)

    # -------------------------------OUTPUT----------------------------------
    if os.path.exists('output.txt'):
        open('output.txt', 'w').writelines(ans)
    else:
        sys.stdout.write(f'{ans}')


if __name__ == '__main__':
    main()
