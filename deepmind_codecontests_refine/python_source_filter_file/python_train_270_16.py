def main():
    n = lie()
    a = [lie() for i in range(n)]
    spec = 3
    for i in range(n):
        if a[i] == spec:
            print("NO")
            exit()
        if a[i] == 1:
            spec = 2 if spec == 3 else 3
        elif a[i] == 2:
            spec = 1 if spec == 3 else 1
        else:
            spec = 1 if spec == 2 else 2
    print("YES")


def fun(m, n, s, k):
    return


def fun2(s):
    return


from sys import *
import inspect
import re
from math import *
import threading
from collections import *
from pprint import pprint as pp
mod = 998244353
MAX = 10**5


def lie():
    return int(input())


def liee():
    return map(int, input().split())


def array():
    return list(map(int, input().split()))


def deb(p):
    for line in inspect.getframeinfo(inspect.currentframe().f_back)[3]:
        m = re.search(r'\bdeb\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)', line)
        print('%s %d' % (m.group(1), p))


def vector(size, val=0):
    vec = [val for i in range(size)]
    return vec


def matrix(rowNum, colNum, val=0):
    mat = []
    for i in range(rowNum):
        collumn = [val for j in range(colNum)]
        mat.append(collumn)
    return mat


def dmain():
    setrecursionlimit(100000000)
    threading.stack_size(40960000)
    thread = threading.Thread(target=main)
    thread.start()


if __name__ == '__main__':
    # main()
    dmain()
