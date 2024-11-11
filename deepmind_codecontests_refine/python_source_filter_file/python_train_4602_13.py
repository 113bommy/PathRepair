for _ in range(int(input())):
    n=int(input())
    if n == 1:
        print(2, 5)
    na=list(map(int,input().split()))
    m=int(input())
    ma=list(map(int,input().split()))
    e1=0
    for i in na:
        if i%2==0:
            e1+=1
    e2=0
    for i in ma:
        if i%2==0:
            e2+=1
    print(e1*e2+(n-e1)*(m-e2))