t=int(input())
for _ in range(t):
    n,x,m=list(map(int,input().split()))
    l1=-1
    r1=-1
    flag=0
    for i in range(m):
        l,r=list(map(int,input().split()))
        if(flag==0):
            if(l<=x and r>=x):
                if(l1==-1 and r1==-1):
                    l1=l
                    r1=r
                    flag=1
        else:
            if(r<l1):
                pass
            elif(l>r1):
                pass
            else:
                if(l<=l1):
                    l1=l
                if(r>=r1):
                    r1=r1
    print(r1)
        
                
