import sys
sys.setrecursionlimit(10**7)

def f(a,b):
    if a==b:return a
    if not a<b:a,b=b,a
    return 2*(b//a)*a+f(a,b%a) if b%a else 2*(b//a)*a-1

N,X=map(int,input().split())
print(f(X,N-X)+N)