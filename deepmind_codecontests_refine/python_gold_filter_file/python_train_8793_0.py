def foo(n,m):
    if n >= m:
        return n-m
    elif m%2 == 0:
        return 1 + foo(n,m/2)
    else :
        return 1 + foo(n,m+1)

if __name__ == "__main__":
    n,m = map(int,input().strip().split())
    print(int(foo(n,m)))
