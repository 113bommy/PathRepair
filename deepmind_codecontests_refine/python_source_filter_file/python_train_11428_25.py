n,x,m=map(int,input().split())
r=[]
s=set()
ans=x
a=x
for i in range(n-1):
    b=a*a%m
    if b in s:
        j = r.index(b)
        N = n-j
        T = i-j
        S = sum(r[j:i])
        ans += N//T*S
        N %= T
        ans += sum(r[j:j+N])
        break
    else:
        ans+=b
        s.add(b)
        r.append(b)
        a=b
print(ans)
    