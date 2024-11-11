def f(n,m):
    if n >= m:
        return n-m
    else:
        if m%2==0:
            return f(n,m//2)+1
        else:
            return f(n,m//2)+2

n,m=list(map(int,input().split()))
print(f(n,m))