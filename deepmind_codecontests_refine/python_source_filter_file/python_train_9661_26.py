from bisect import bisect_left
n=int(input())
a=list(map(int,input().split()))
a.sort()
if(a[0]>0):
    print(sum(a[1:])-a[0])
    ans=a[0]
    for i in a[1:n-1]:
        print(ans,i)
        ans-=i
    print(a[-1],ans)
elif(a[-1]<0):
    print(a[-1]-sum(a[:n-1]))
    ans=a[-1]
    for i in a[:n-1]:
        print(ans,i)
        ans-=i
else:
    print(sum([abs(i) for i in a]))
    b=bisect_left(a,0)
    ans=a[0]
    tmp=a[-1]
    for i in a[b:n-1]:
        print(ans,i)
        ans-=i
    for i in a[1:b]:
        print(tmp,i)
        tmp-=i
    print(tmp,ans)