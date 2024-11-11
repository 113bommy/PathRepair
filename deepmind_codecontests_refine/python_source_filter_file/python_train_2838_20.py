t=int(input())
while t>0 :
    a=list(map(int,input().split()))
    maxx=max(a)
    minn=min(a)
    count=a.count(maxx)
    if count>=2:
        print("YES")
        print(minn, minn-1, maxx)
    else :
        print("NO")
    t-=1