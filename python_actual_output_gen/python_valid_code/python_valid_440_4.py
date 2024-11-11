for _ in range(int(input())):
    n=int(input())
    l=[int(x) for x in input().split()]
    h=1
    flag=0
    if l[0]==1:
        h+=1
    for i in range(2,n):
        if l[i-1]==0 and l[i]==1:
            h+=1
        if l[i-1]==1 and l[i]==1:
            h+=5
        if l[i-1]==0 and l[i]==0:
            flag=1
    if flag:
        print(-1)        
    else:
        print(h)
    