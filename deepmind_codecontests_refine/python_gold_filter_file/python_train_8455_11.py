for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    flag=0
    
    for i in range(n):
        if i+2<n:
            if l[i] in l[i+2:]:
                flag=1
                break
    if flag==1:
        print('YES')
    else:
        print('NO')
            
            
        