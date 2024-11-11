MOD = 10**9 + 9

n,m,k = map(int,input().split())

x = (n//k) + m -n

if (n - n//k) < m:
    x = n//k +m -n
    ans = pow(2,x+1,MOD)-2
    ans = ans*k+m-x*k
    print(ans%MOD)

else :
    print(m)
