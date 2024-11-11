t=int(input())
while(t>0):
    n=int(input())
    st=input()
    l=[]
    l.append(st)
    for k in range(2,n+1):
        if k%2==0:
            s=st[k-1:n] + st[0:k-1][::-1]
            l.append(s)
        else:
            s=st[k-1:n] + st[0:k-1]
            l.append(s)
    p=l.copy()
    l.sort()
    print(l[0])
    print(p.index(l[0])+1)
    t-=1
