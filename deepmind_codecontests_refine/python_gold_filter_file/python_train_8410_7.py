n,k = map(int,input().split())

a = list(map(int,input().split()))

s = sum(a)

dlist = []
for p in range(1,int(s**(1/2))+1):
    if s % p == 0:
        dlist.append(p)
        dlist.append(int(s/p))

anslist = []

for d in dlist:
    r = [a[_] % d for _ in range(n)]
    r.sort()

    w = [r[0]]#累積和
    for i in range(1,n):
        w.append(w[-1]+r[i])
    
    can = "no"
    for j in range(0,n):
        if max(w[j],d*(n-j-1)-w[n-1]+w[j])<=k:
            can = "yes"
            break
    if can == "yes":
        anslist.append(d)

print(max(anslist))
