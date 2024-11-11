#!/usr/bin/env python3

def main():
    K = int(input())
    S = input()
    N = len(S)
    M = N+K
    # print(N,K,M)
    p = 10**9+7
    a = [None] * (M+1)
    inva = [None] * (M+1)
    a[0] = 1
    
    for i in range(1, M+1):
        a[i] = i * a[i-1] % p
    
    inva[M] = pow(a[M],p-2,p)
    for i in range(M):
        inva[M-i-1] = inva[M-i] * (M-i) % p

    ans = 0
    for i in range(K+1):
        tmp = a[N+K-i-1]*inva[N-1]%p
        tmp = tmp*inva[K-i]%p
        tmp *= pow(25,K-i,p)
        tmp %= p
        tmp *= pow(26,i,p)
        tmp %= p
        ans = ans + tmp
        ans %= p
    print(ans)

if __name__ == "__main__":
    main()
