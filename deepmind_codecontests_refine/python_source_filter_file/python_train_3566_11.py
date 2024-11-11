t=int(input())
for _ in range(t):
    n=int(input())
    inp = list(map(int,input().split()))
    if n==1:
        print (0)
    else:
        lef=[0]
        ri=[max(0,inp[1]-inp[0])]
        for i in range(1,len(inp)):
            if i%2==1:
                lef.append(0)
                ri.append(0)
                continue
            if i-2>=0:
                lef.append(max(0,lef[-2]+inp[i-1]-inp[i]))
            else:
                lef.append(max(0,inp[i-1]-inp[i]))
            if i+1<len(inp):
                if i-2>=0:
                    ri.append(max(0,ri[-2]+inp[i+1]-inp[i]))
                else:
                    ri.append(max(0,inp[i+1]-inp[i]))
        ans=0
        for i in range(0,len(inp),2):
            ans+=inp[i]
        ans+=max(max(ri),max(lef))
        print (ans)