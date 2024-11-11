# '''
#      |\_/|                  
#      | @ @   Woof! 
#      |   <>              _  
#      |  _/\------____ ((| |))
#      |               `--' |   
#  ____|_       ___|   |___.' 
# /_/_____/____/_______|
# I am here to guard this code, woof!
# '''
 
import sys
from sys import stdin, stdout
from math import ceil, floor, sqrt, log, log2, log10
from collections import Counter
 
int_max = float('inf')
int_min = -(float('inf'))
ANS = []
# infile = open(sys.argv[1], "r")
# input = infile.readline
input = stdin.readline
 
def solve():
    pass

def lcs(X , Y):
    # find the length of the strings
    n = len(X)
    m = len(Y)
    maxx = int_min
    for t in range(1):
        it = t
        total = 0
        for j in range(n):
            if it < m and X[j] == Y[it]:
                it += 1
                total += 1
        maxx = max(maxx, total)

    return maxx        

t = int(input())
# t = 1
 
for i in range(t):
    n = int(input())
    # n, k = map(int, input().split())
    # arr =  list(map(int, input().split()))
    # arr = list(input())
    # s = input().strip()
    s = str(n)
    minn = int_max
    for i in range(31):
        t = str(2**i)
        l = lcs(s, t)
        # print(l, len(s), len(t), len(s) - l + len(t) - l, 2**i)
        minn = min(minn, len(s) - l + len(t) - l)
    print(minn)

   
print('\n'.join(ANS))