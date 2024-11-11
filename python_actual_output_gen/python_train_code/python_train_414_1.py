t=int(input())
for i in range(t):
    cost=[]
    cs=0
    ans=1
    ls2=[]
    ls1=[int(a) for a in input().split()]
    a,b,p=ls1[0],ls1[1],ls1[2]
    s=str(input())
    for aa in s:
        ls2.append(aa)
        l=ls2[0]
        ind=0
    for j in range(1,len(ls2)):
        
        if l!=ls2[j] or j==len(ls2)-1:
            if l=='A':
                cost.append([a,j-ind])
                
            else:
                cost.append([b,j-ind])
            l=ls2[j]
            ind=j
        else:
            pass
    for k in range(1,len(cost)+1):
        cs += cost[-k][0]
        if cs > p:
            break
        else:
            pass
    if cs<p:
        ans=1
    else:
        for z in range(len(cost)-(k-1)):
            ans+=cost[z][1]
    print(ans)