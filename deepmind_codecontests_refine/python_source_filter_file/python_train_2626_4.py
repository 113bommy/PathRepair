t=int(input())
for i in range(0,t):
    n,p,k=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    b=a[1:]
    flag=0
    money=p
    count=0
    for i in range(0,len(a)):
        if flag==0:
            if a[i]<=money:
                count+=1
                money-=a[i]
                flag=1
            else:
                break
        elif flag==1:
            if money+a[i-1]>a[i]:
                count+=1
                money=money + a[i-1] - a[i]
                flag=0
            else:
                break
    c=count
    if p>=a[0]:
        money=p-a[0]
        count=1
        flag=0
        for i in range(0,len(b)):
            if flag==0:
                if b[i]<=money:
                    count+=1
                    money-=b[i]
                    flag=1
                else:
                    break
            elif flag==1:
                if money+b[i-1]>=b[i]:
                    count+=1
                    money=money + b[i-1] - b[i]
                    flag=0
                else:
                    break
    if count>c:
        c=count
    print(c)
