for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    s=set()
    ans=0
    f=1
    for i in range(0,len(a)):
        ans = (i+a[i])%n
        if ans in s:
            f=1
            break
        else:
            s.add(ans)
    if f==0:
        print("NO")
    else:
        print("YES")