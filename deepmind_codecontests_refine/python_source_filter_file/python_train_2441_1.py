n,m,k=map(int,input().split())
curx,cury=1,1
flag=1
def construct(lim):
    cnt=0
    global curx,cury,flag
    while cnt<lim:
        cnt+=1
        if curx>n or cury>m:
            break
        if flag!=0:
            print(curx,cury,end=' ')
            cury+=1
            if cury>m:
                flag=0
                cury=m
                curx+=1
        elif flag==0:
            print(curx,cury,end=' ')
            cury-=1
            if cury<1:
                curx+=1
                cury=1
                flag=1
    print()

for _ in range(1,k):
    print(3,end=' ')
    construct(3)

print(m*n-(k-1)*(3),end=' ')
construct(m*n-(k-1)*(3))
    
    
