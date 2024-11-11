l=[]
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if sum(a)==0:
        l.append("NO")
        continue
    n=0
    p=0
    for i in range(len(a)):
        if a[i]>0:
            p=p+a[i]
        else:
            n=n+a[i]
    if abs(n)<p:
        l.append("YES")
        a.sort(reverse=True)
        b=[str(a[i]) for i in range(len(a))]
        l.append(" ".join(b))
    else:
        l.append("YES")
        a.sort()
        b = [str(a[i]) for i in range(len(a))]
        l.append(" ".join(b))
for i in l:
    print(i)