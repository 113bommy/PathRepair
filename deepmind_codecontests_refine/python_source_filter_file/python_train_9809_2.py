t=int(input())
for _ in range(t):
    n,x=map(int,input().split())
    string=input()
    num=[0]
    for i in string:
        if i=='1':
            num.append(num[-1]-1)
        else:
            num.append(num[-1]+1)
    ans=0
    isInfi=False
    for i in num[:-1]:
        if num[n]==0:
            if i==x:
                isInfi=True
        elif abs(x-i)%abs(num[n])==0:
            if  (x-i)/(num[n])>0:
                ans+=1
    if isInfi:
        print(-1)
    else:
        print(ans)
            