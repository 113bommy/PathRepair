import sys
import collections
from io import BytesIO, StringIO

# input = BytesIO().readline
input = sys.stdin.readline
def rints():
    return map(int, input().strip().split())
def rint():
    return int(input().strip())

n, p, w, d = rints()
for i in range(10**5+1):
    if (p-d*i)%w == 0:
        x = (p-d*i)//w
        if x >= 0 and x + i <= n:
            print(x, " ", i+x, " ", n-i-x)
            exit(0)

print(-1)

    



