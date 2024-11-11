for i in range(int(input())):
    l,r=map(int,input().split())
    L=list(bin(l))
    R=list(bin(r))
    L=L[2:]
    R=R[2:]
    w=0
    c=0
    L=['0']*(len(R)-len(L))+L
    #print(L,R)
    ans=0
    if l==r:
        print(l)
        continue
    for i in range(len(R)):
        if L[i]!=R[i]:
            for j in range(i+1,len(R)):
                if(R[j]=='0'):
                    w=1
            if w==1:
                ans=c+(2**(len(R)-i-1))-1
                print(ans)
                break
            else:
                ans=c+(2**(len(R)-i))-1
                break
        elif L[i]=='1':
            c=c+(2**(len(R)-i-1))
    print(ans)