N, X = map(int, input().split())
def f(n, x):
    if x ==0:
        return 0
    elif n == 0:
        return 1
    elif x <= 2**n - 1:
        return f(n-1, x-1)
    else:
        return 2**n+f(n-1, x-2**(n+1)+1)
print(f(N, X))