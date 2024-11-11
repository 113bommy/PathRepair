m,n=(int(x) for x in input().split())
z=[]
for i in range(m):
    z.append([int(x) for x in input().split()])
def f(n):
    x=1
    for i in range(1,n+1):
        x*=i
    return x
def k(n,k):
    return f(n)/(f(k)*(f(n-k)))
def c(n):
    x=0
    for i in range(2,n+1):
       x+=k(n,i)
    return x
def sum(n,z,p=0):
    s=0
    if p==0:
        for i in z:
            s+=i[n]
        return s
    else:
        for i in z[n]:
            s+=i
        return s
q=0
for i in range(n):
    a=sum(i,z,0)
    b=m-a
    q=q+c(a)+c(b)   
for i in range(m):
    a=sum(i,z,1)
    b=n-a
    q=q+c(a)+c(b)
print(int(q+m*n))