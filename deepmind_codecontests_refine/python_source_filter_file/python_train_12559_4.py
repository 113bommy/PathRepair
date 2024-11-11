t=int(input())
for i in range(t):
    n=int(input())
    tm=0
    ans=""
    for j in range(n):
        l,r=map(int,input().split())
        if tm>=r:
            ans+="0"+" "
        else:
            if tm<=l:
                tm+=1
            else:
                tm=l
            ans+=str(tm)+" "
    print(ans)
