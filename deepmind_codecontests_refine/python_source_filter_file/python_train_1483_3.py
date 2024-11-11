# from future import print_function,division
# range = xrange
import sys
input = sys.stdin.readline
# sys.setrecursionlimit(10**9)
from sys import stdin, stdout

def main():
    n,m = [int(s) for s in input().split()]
    l = [int(s) for s in input().split()]
    sums = [0]*m
    sums[0] = l[0]
    for i in range(1,m):
        sums[i] = sums[i-1]+l[i]
    ww = 0
    for i in range(m):
        ww = max(ww, i+l[i])
    if max(ww,m+l[-1]-1)>n:
        print(-1)
    elif sums[-1]<n:
        print(-1)
    elif m==1:
        print(1)
    else:
        ans = [0]*m
        w = m+l[-1]-1
        ans[-1] = n-l[-1]+1
        j = m-2
        while w + l[j]-1 < n:
            w += (l[j]-1)
            ans[j] = ans[j+1]-l[j]+1
            j-=1
        if j>=0:
            for i in range(j+1):
                ans[i] = i+1
        print(*ans)


if __name__== '__main__':
    main()