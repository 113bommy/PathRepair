n,x=map(int,input().split())
a,p=[1],[1]
for i in range(n):
    a.append(3+2*a[-1])
    p.append(1+2*a[-1])
def f(l,x):
    if l==0:return int(x==1)
    if x<=1+a[n-1]:
        return  f(l-1,x-1)
    else:return p[l-1]+1+f(l-1,x-2-a[l-1])
print(f(n,x))