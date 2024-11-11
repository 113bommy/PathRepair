def popcnt(n):
    return bin(n).count("1")

def f(n):
    cnt = 0
    while n>0:
        n = n%popcnt(n)
        cnt += 1
    return cnt

def solve(X):
    Y = int(X, 2)
    c = X.count("1")
    m, p = c-1, c+1
    Ym, Yp = Y%m if m else 0, Y%p
    for i in range(N):
        if X[i] == "1":
            Y = (Ym - pow(2,N-i-1,m))%m if Ym else -1
        else:
            Y = (Yp + pow(2,N-i-1,p))%p
        print(f(Y) + 1 if Y!=-1 else 0)

N = int(input())
solve(input())

