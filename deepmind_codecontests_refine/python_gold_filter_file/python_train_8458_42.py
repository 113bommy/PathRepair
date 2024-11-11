for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    q=[]
    for i in l:
        if i not in q:
            q.append(i)  
    print(*q)