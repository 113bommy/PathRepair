x,y = map(int, input().split())

mod = 10**9+7

def choose(n,r):
    p,q = 1,1
    for i in range(r):
        p = p*(n-i)%mod
        q = q*(i+1)%mod
    return p * pow(q,mod-2,mod) % mod # modの世界では逆元はpow(x,mod-2)をかけることと同じ

n = (2*x-y)/3
m = (y-n)/2

if n >= 0 and m >= 0 and int(n)*10 == n*10 and int(m)*10 == m*10:
    ans = choose(int(m+n), int(m))
else:
    ans = 0
print(ans)