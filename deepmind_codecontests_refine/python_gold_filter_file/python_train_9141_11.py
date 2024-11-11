import sys
input = sys.stdin.readline
from heapq import heappushpop

N = int(input())
A = [int(x) for x in input().split()]

# B_x = max {A_y | y\subset x}
# と思ったが、2元ずつ持つ必要がある。
# (値、何番から来たか)
B = []
for n,a in enumerate(A):
    arr = [(0,0),(a,n)]
    m = n
    while m:
        bit = m & (-m)
        (x,i),(y,j) = B[n-bit]
        if (x,i) != arr[-1]:
            heappushpop(arr,(x,i))
        if (y,j) != arr[-1]:
            heappushpop(arr,(y,j))
        m -= bit
    B.append(arr)

answer = [0]
for (x,i),(y,j) in B[1:]:
    z = answer[-1]
    if z < x + y:
        z = x + y
    answer.append(z)
print('\n'.join(map(str,answer[1:])))

