'''input
3 8
'''
# practicing a skill right after sleep improves it a lot quickly
from sys import stdin, setrecursionlimit
import math

# main starts
n, m = list(map(int, stdin.readline().split()))
p = pow(3, n - 1, m)
print((2 * p) % m)