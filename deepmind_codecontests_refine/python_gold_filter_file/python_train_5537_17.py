a1 = int(input())
a2 = int(input())
k1 = int(input())
k2 = int(input())
n = int(input())

def st(a,k,n):
    if a*k >= n:
        return n//k
    return a

if k2 > k1:
    k1,k2 = k2,k1
    a1,a2 = a2,a1

mi = max(0,n - (k1-1)*a1 - (k2-1)*a2)

ma = st(a2,k2,n)
na = n - ma*k2
ma += st(a1,k1,na)

print(mi,ma)
