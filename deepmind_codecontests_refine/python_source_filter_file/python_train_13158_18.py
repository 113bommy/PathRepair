n,k = map(int, input().split())
a = list(map(int,input().split()))
sm = []
p = [a[0]]
for i in range(1,n):
    p.append(p[i-1]+a[i])
sm = [p[k-1]]
for i in range(1,n-k+1):
    sm.append(p[i+k-1]-p[i-1])
a=n-2*k
b=n-k
maxb = b
val = sm[a]+sm[b]
for i in range(a-1,-1,-1):
    maxb = i+k if sm[maxb] < sm[i+k] else maxb
    if(val < sm[i]+sm[maxb]):
        b = maxb
        a = i
        val = sm[i]+sm[maxb]
print(a+1,b+1)