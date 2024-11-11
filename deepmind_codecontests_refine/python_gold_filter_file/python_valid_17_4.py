for hbdcjcsk in range(int(input())):
    n=int(input())
    a={}
    for i in range(1,n+1):
        l=list(map(int,input().split()))
        a[i]=l
    ans=1
    for i in a:
        if a[ans]!=a[i]:
            count=0
            if a[i][0]>a[ans][0]:
                count+=1
            if a[i][1]>a[ans][1]:
                count+=1
            if a[i][2]>a[ans][2]:
                count+=1
            if a[i][3]>a[ans][3]:
                count+=1
            if a[i][4]>a[ans][4]:
                count+=1
            if count<3:
                ans=i
    for i in a:
        if a[ans]!=a[i]:
            count=0
            if a[i][0]<a[ans][0]:
                count+=1
            if a[i][1]<a[ans][1]:
                count+=1
            if a[i][2]<a[ans][2]:
                count+=1
            if a[i][3]<a[ans][3]:
                count+=1
            if a[i][4]<a[ans][4]:
                count+=1
            if count>=3:
                ans=-1
                break
    print(ans)