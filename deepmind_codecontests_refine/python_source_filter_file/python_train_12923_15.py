import math
def p(n):
    a=[]
    while n % 2 == 0:
        a.append(int(2))
        n = n / 2

    for i in range(3, int(math.sqrt(n)) + 1, 2):

        while n % i == 0:
            a.append(int(i))
            n = n / i

    if n > 2:
        a.append(int(n))
    return a

def solve(m,q,i):
    j=2
    s=int(m//int((math.pow(i,1))))
    r=int(m//int((math.pow(i,1))))
    while(r!=0):
        r=int(m/int((math.pow(i,j))))
        s+=r
        j+=1
    l=int(s//q)
    return l


n,m=map(int,input().split())
c=dict()
d=p(m)
for j in range(len(d)):
    if d[j] in c.keys():
        c[d[j]]+=1
    else:
        c[d[j]]=1
f=set(d)
m=10000000000000000000000000000
for j in f:
    q=c[j]
    s=solve(n,q,j)

    if s<m:
        m=s
print(m)