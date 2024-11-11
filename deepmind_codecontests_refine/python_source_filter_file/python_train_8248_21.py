for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    p=set(l)
    
    for i in range(1,max(l)+1):
        s=set()
        for j in l:
            s.add(i^j)
        # print(s)
        
        if s==p:
            print(i)
            break
    else:
        print(-1)
