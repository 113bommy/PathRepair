T=int(input())
for i in range(T):
    n=int(input())
    seg=[]
    for i in range(n):
        seg.append([int(i) for i in input().split()]+[i])
    seg.sort()
    
    gp=[1]*n
    ans=[-1]*n
    end=seg[0][1]
    for i in range(n):
        if seg[i][0]<=end:
            gp[i]=gp[i-1]
        else:
            gp[i]=gp[i-1]+1
        end=seg[i][1]
        ans[seg[i][2]]=gp[i]
        
    if gp[-1]==1:
        print(-1)
    else:
        for x in ans:
            if x==1:
                print('1',end=' ')
            else:
                print('2',end=' ')
        print()

        
        
        
