for _ in range(int(input())):
    n,m=map(int,input().split())
    a=[]
    count=0
    for i in range(n):
        a.append(input())
    for i in range(n-1):
        if a[i][n-1]=="R":
            count+=1
    for i in a[n-1]:
        if i=="D":
            count+=1
    print(count)