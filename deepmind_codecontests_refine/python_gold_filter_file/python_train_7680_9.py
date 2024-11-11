def modinv(a,m):
    return pow(a,m-2,m)


n,k = map(int,input().split())
P = 10**9+7



if n-1 <= k:
    N = n + min(n-1,k)
    ans = 1
    for i in range(1,n):
        ans = ans*(N+1-i)*modinv(i,P)%P

else:
    ans = 1
    nCl = 1
    n1Cl = 1
    for l in range(1,k+1):
        nCl = nCl*(n+1-l)*modinv(l,P)%P
        n1Cl = n1Cl*(n-l)*modinv(l,P)%P
        ans = (ans+nCl*n1Cl)%P

print(ans)
