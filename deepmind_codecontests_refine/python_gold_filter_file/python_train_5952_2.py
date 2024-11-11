from sys import stdin,stdout
I = stdin.readline
print=stdout.write
for _ in range(int(I())):
    n=int(I())
    a=list(map(int,I().split()))
    d=dict()
    for i in a:
        if i in d:
            d[i]+=1
        else:
            d[i]=1
    l=list(d.values())
    l.sort(reverse=True)
    ans=[l[0]]
    al=1
    t=l[0]
    for i in range(1,len(l)):
        if t-l[i]>0:
            ans.append(l[i])
            t=l[i]
        else:
            temp=l[i]-t
            temp+=1
            if l[i]-temp<=0:
                break
            else:
                t=l[i]-temp
                ans.append(t)
    print(str(sum(ans))+'\n')