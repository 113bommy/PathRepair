import sys
sys.setrecursionlimit(100000)
from math import floor
n,x=map(int,input().split())
ans=0
def f(x,y):
    if y%x==0:
        return y//x*2-x
    return 2*x*(y//x)+f(y%x,x)
print(n+f(min(x,n-x),max(x,n-x)))