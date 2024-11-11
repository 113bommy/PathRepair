n,k=map(int,input().split())
p=[int(i)-1 for i in input().split()]
c=[int(i) for i in input().split()]
max_c=min(c)

def calc(x):
    global n,k
    next=x
    ma=max_c
    s=0
    l=[]
    for i in range(n):
        next=p[next]
        s+=c[next]
        l.append(c[next])
        ma=max(ma,s)
        if next==x:
            break
    if s<=0:
        return ma

    cycle=k//(i+1)
    rest=k%(i+1)
    ans=(cycle-1)*s+ma
    f=s*cycle
    for j in range(rest):
        f+=l[j]
        ans=max(ans,f)
    return ans

A=max_c
for start in range(n):
    A=max(A,calc(start))
print(A)
