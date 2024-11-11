def nCr(n,r):
    com = 1
    for i in range (1,r+1):
        com =com*(n+1-i)//i
    return com
N,K = map(int,input().split())
mod = (10**9)+7
for i in range(1,K+1):
    com1 = nCr(N - K + 1, i)
    com2 = nCr(K-1,i-1)
    print((com1*com2)%mod)
