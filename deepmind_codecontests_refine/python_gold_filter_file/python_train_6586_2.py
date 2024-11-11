import sys
sys.setrecursionlimit(10**7)
input=sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))
def calc(l,r,h):
    if l>=r:
        return 0
    m=a.index(min(a[l:r]),l,r)
    return min(r-l,a[m]-h+calc(l,m,a[m])+calc(m+1,r,a[m]))
print(calc(0,n,0))