t=int(input())
for r in range(t):
    n=int(input())
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    flag=1
    diff=-9999999
    count=0
    count0=0
    for i in range(0,n):
        if (l1[i]-l2[i])!=diff:
            diff=l1[i]-l2[i]
            count+=1
        if (l1[i]-l2[i])==0:
            count0+=1
        if (l1[i]-l2[i])>0:
            flag=0
    if flag==1 and (count-count0)<=1:
        print("YES")
    else:
        print("NO")

        
