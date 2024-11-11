def com(n,r,mod):
    k=min(r,n-r)
    C=1
    for i in range(1,k+1):
        C=(C*(n+1-i)*pow(i,mod-2,mod))%mod
    return C
x,y=map(int,input().split())
mod = 10 ** 9 + 7
n = (2 * y - x) // 3
m = (2 * x - y) // 3
if (x + y) % 3 != 0 or (n<0 and m<0):
    print(0)
    exit()

print(com(n+m,n,mod))
