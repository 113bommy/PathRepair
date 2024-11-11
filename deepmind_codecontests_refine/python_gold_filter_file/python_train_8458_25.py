t=int(input())
while(t!=0):
    n=int(input())
    p=[]
    l=list(map(int,input().split()))
    for i in l:
        if i not in p:
            p.append(i)
    print(*p)        
    t=t-1