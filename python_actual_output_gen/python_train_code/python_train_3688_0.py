for i in range(int(input())):
    a,b=map(int,input().split())
    c=list(map(int,input().split()))
    ev=0
    od=0
    for i in c:
        if i%2==0:
            ev+=1
        else:
            od+=1
    ans=False
    for i in range(1,od+1,2):
        if ev>=b-i and b-i>0:
            ans=True
            break
    if ans:
        print("Yes")
    else:
        print("No")