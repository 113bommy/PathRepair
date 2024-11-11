n=int(input())
a=[]
for i in range(n):
    m=int(input())
    c=0
    d=0
    e=0
    ans=[]
    while m%5==0:
        c+=1
        m=m/5
    while m%3==0:
        d+=1
        m=m/3
    while m%2==0:
        e+=1
        m=m/2
    if m!=1:
        ans=-1
    else:
        ans=3*c+2*d+e
    a.append(ans)
for i in a:
    print(i)
