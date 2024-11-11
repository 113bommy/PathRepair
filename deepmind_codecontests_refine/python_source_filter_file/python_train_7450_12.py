

def getSec(n, k):
    if n == 1:
        return 1
    return getSec(n - 1, k) if k < 1 << (n - 1) else n if k == 1 << (n-1) else getSec(n-1, k-1 << (n-1))


n, k = (int(i) for i in input().split(' '))
print(getSec(n, k))
