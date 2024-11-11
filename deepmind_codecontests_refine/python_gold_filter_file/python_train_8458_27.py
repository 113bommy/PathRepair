t=int(input())
while(t!=0):
    n=int(input())
    mk=[]
    l=list(map(int,input().split()))
    for i in l:
        if i not in mk:
            mk.append(i)
    print(*mk)        
    t=t-1
