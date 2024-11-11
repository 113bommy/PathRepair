n = int(input())
l = list(map(int, input().strip().split()))
m = list(map(int, input().strip().split()))
def gcd(a,b):
    mn = min(a,b)
    mx = max(a,b)
    if mx % mn == 0:
        return mn
    else:
        return gcd(mn,mx%mn)
zero = 0
ans = 0
c = 0
d =  {}
for i in range(n):
    if m[i] == 0 and l[i] == 0:
        c += 1
    elif m[i] == 0:
        zero += 1
        ans = max(ans,zero)
    elif l[i] == 0: continue
    else:
        h = int(abs(m[i]))
        w = int(abs(l[i]))
        g = int(gcd(h,w))
        x = h/g
        y=  h/g
        if int(abs(m[i] + l[i])) != h + w:
            x = - x
        d[(x,y)] = d.get((x,y),0) + 1
        ans = max(ans,d[(x,y)])
print (ans + c)