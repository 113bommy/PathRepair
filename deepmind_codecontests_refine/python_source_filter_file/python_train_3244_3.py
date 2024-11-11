for _ in range(int(input())):
    n=int(input())
    ar=list(map(int,input().split()))
    c1=0
    c2=0
    c3=0
    for i in range(n):
        if ar[i]%3==0:
            c3+=1
        elif ar[i]%3==1:
            c1+=1
        else:
            c2+=1
    ans=0
    ans+=c3
    ans+=min(c2,c1)
    c_2=c2-min(c2,c1)
    c_1=c1-min(c1,c2)
    ans+=(c1//3);ans+=(c2//3)
    print(ans)