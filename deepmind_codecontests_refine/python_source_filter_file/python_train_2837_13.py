for _ in range(int(input())):
    n,m=map(int,input().split())
    lst1=[]
    cnt1,cnt2=0,0
    for i in range(n):
        lst=list(map(int,input().split()))
        if 1 not in lst:
            cnt1+=1
        lst1.append(lst)
    for i in range(m):
        for j in range(n):
            if lst1[j][i]==1:
                cnt2+=1
                break
    if min(cnt1,cnt2)%2==0:
        print("Vivek")
    else:
        print("Ashish")