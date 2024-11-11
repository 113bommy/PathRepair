n,m,s=list(map(int,input().split()))
def f(x):
    k=(x-1)//(s)
    return (k+1)*(x-k*s)
print(f(n)*f(m))