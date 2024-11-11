# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n = int(input())
if n % 2 == 1:
    print(0)
else:
    print(n)
