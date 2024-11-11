N,X=map(int,input().split())
def f(a,b):
    if a>b:
        return f(b,a)
    if b%a==0:
        return a*(2*(b//a) + 1)
    return 2*(b//a) + f(b%a,a)
print(N+f(X,N-X))


