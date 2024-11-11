def gcd(a,b):
    if a>b:
        return gcd(b,a)
    if a == 0:
        return b
    return gcd(b%a,a)
q = int(input())
for i in range(q):
    n = int(input())
    lol = list(map(int,input().split()))
    lol.sort(reverse = True)
    x,a = map(int,input().split())
    y,b = map(int,input().split())
    if x<y:
        x,y = y,x
        a,b = b,a
    k = int(input())
    ans = 0
    l,r = 0,n
    baaa = a*b//gcd(a,b)
    m = n
    kol = 0
    for i in range(m // baaa):
        ans += lol[i] * (x + y) // 100
    for j in range(m // baaa, m // a):
        ans += lol[j] * x // 100
        kol += 1
    for j in range(m // baaa+kol, m // b+kol):
        ans += lol[j] * y // 100
    if k > ans:
        print(-1)
    else:
        l, r = 0, n

        while r-l>1:
            kol = 0
            m = (l+r)//2
            ans = 0
            for i in range(m//baaa):
                ans+=lol[i]*(x+y)//100
            for j in range(m//baaa,m//a):
                ans+=lol[j]*x//100
                kol += 1
            for p in range(m//baaa+kol,m//b+kol):
                ans+=lol[p]*y//100
            #print(m,ans,baaa)
            if k>ans:
                l = m
            else:
                r = m
        print(r)
