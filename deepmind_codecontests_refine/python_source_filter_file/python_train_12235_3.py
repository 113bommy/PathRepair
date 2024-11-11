# import sys, math
 
# sys.setrecursionlimit(10 ** 8)
# def getnum(t=int): return t(sys.stdin.buffer.readline())
# def numline(t=int): return map(t, sys.stdin.buffer.readline().split())
# def numread(t=int): return map(t, sys.stdin.buffer.read().split())
# def getstr(): return sys.stdin.readline().strip()
# def strline(): return sys.stdin.readline().strip().split()
# def strread(): return sys.stdin.read().strip().split()
# import numpy as np
# from time import time

n = int(input())
slots = 2*n - 2
starts = slots // 2
permutations_border = 3 * 4**(n-2-1)
permutations = 4**(n-2-2) * 3 * 3

r = 4 * ((starts-2) * permutations + 2 * permutations_border)
print(r)
