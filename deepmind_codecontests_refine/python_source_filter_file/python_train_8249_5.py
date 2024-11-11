def f(c):
    if c=='1':
        return '0'
    else:
        return '1'
for _ in range(int(input())):
    n=int(input())
    a=list(input())
    b=list(input())
    l=[]
    i=n-1
    j=n-1
    am=True
    while j>=0:
        if am:
            if a[i]!=b[j]:
                if a[i-j]==b[j]:
                    l.append(1)
                    a[i-j]=f(a[i-j])
                l.append(j+1)
                am=False
                i-=j
                i+=1
            else:
                i-=1
        else:
            if a[i]==b[j]:
                if a[i+j]!=b[j]:
                    l.append(1)
                    a[i+j]=f(a[i+j])
                l.append(j+1)
                am=True
                i+=j
                i-=1
            else:
                i+=1
        j-=12
    l1=[len(l)]+l
    print(*l1)
            