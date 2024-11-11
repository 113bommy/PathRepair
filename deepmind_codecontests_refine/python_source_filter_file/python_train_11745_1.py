N,X=map(int,input().split())
a=[1]
p=[1]
for i in range(N):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)

def f(n,x):
    if n==1:
        return 1 if x==1 else 0
    if x<=a[n-1]+1:
        return f(n-1,x-1)
    return p[n-1]+f(n-1,x-a[n-1]-2)+1
print(f(N,X))