import sys
import string
import math
from collections import defaultdict
from functools import lru_cache
from collections import Counter
from fractions import Fraction

def mi(s):
    return map(int, s.strip().split())

def lmi(s):
    return list(mi(s))

def tmi(s):
    return tuple(mi(s))

def mf(f, s):
    return map(f, s)

def lmf(f, s):
    return list(mf(f, s))

def js(lst):
    return " ".join(str(d) for d in lst)

def line():
    return sys.stdin.readline().strip()

def linesp():
    return line().split()

def iline():
    return int(line())

def mat(n):
    matr = []
    for _ in range(n):
        matr.append(linesp())
    return matr

def matns(n):
    mat = []
    for _ in range(n):
        mat.append([c for c in line()])
    return mat

def mati(n):
    mat = []
    for _ in range(n):
       mat.append(lmi(line())) 
    return mat

def pmat(mat):
    for row in mat:
        print(js(row))

def dist(x, y):
    return ((x[0] - y[0])**2 + (x[1] - y[1])**2)**0.5

def fast_exp(x, n):
    if n == 0:
        return 1
    elif n % 2 == 1:
        return x * fast_exp(x, (n - 1) // 2)**2
    else:
        return fast_exp(x, n // 2)**2

def gcd(a, b):
    while b:
        a %= b
        a, b = b, a
    return a

def hamming_d(a, b, i, j):
    count = 0
    w = 0
    for k in range(i, j + 1):
        if a[w] != b[k]:
            count += 1
        w += 1
    return count

def main():
    s1 = line()
    s2 = line()
    
    prefix_b = [ord(s1[0]) - ord('0')]
    for i in range(1, len(s2)):
        prefix_b.append(prefix_b[-1] + ord(s2[i]) - ord('0'))

    count = 0
    for i in range(len(s1)):
        length = len(s2) - len(s1) + 1
        if i == 0:
            num_ones = prefix_b[len(s2) - len(s1) + i]
        else:
            num_ones = prefix_b[len(s2) - len(s1) + i] - prefix_b[i - 1]

        num_zeros = length - num_ones
        if s1[i] == '1':
            count += num_zeros
        else:
            count += num_ones
    print(count)

main()
