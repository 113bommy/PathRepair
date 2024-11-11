for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    su=0
    for i in range(n-1):
        su+=abs(l[i+1]-l[i])
    l1=[l[0]]
    z,cnt=0,0
    if l[1]>l[0]:
         for i in range(n-1):
            if z==1:
                if l[i]>l[i+1]:
                    continue
                else:
                    z=1
                    l1.append(l[i])
            elif z==0:
                if l[i+1]>l[i] :
                    continue
                else:
                    z=0
                    l1.append(l[i])
    else:
        for i in range(n-1):
            if z==0:
                if l[i]>l[i+1]:
                    continue
                else:
                    z=1
                    l1.append(l[i])
            elif z==1:
                if l[i+1]>l[i] :
                    continue
                else:
                    z=0
                    l1.append(l[i])
    l1.append(l[-1])
    print(len(l1))
    print(*l1)
        
            
        
