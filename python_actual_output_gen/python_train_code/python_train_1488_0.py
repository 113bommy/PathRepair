for _ in range(int(input())):
    n=int(input())
    u=False
    s=[]
    k=[]
    l=list(map(int,input().split()))
    for i in range(1,2*n+1):
        if i not in l:
            k.append(i)
    #print(k)
    for i in range(n):
        s.append(l[i])
        for j in range(len(k)):
            #print(k[j],l[i])
            if k[j]>l[i]:
                s.append(k[j])
                del k[j]
                u=True
                break
        if not u:
            print("-1")
            break
    if u and len(s)==2*n:
        print(*s,sep=" ")
    else:
        print("-1")
            
    