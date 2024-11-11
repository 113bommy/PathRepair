from sys import stdin,stdout
nmbr = lambda: int(input())
lst = lambda: list(map(int, input().split()))
PI=float('inf')
def fn(a):
    diff=a[1]-a[0]
    op=0
    for i in range(2,n):
        next=a[i-1]+diff
        if abs(next-a[i])<=1:
            op+=abs(next-a[i])
            a[i]=next
        else:return PI
    return op

for _ in range(1):#nmbr()):
    n=nmbr()
    # n,q=lst()
    a1=lst()
    if n<=2:
        print(0)
        continue
    ans=PI
    for i in range(-1,2):
        for j in range(-1,2):
            a1[0]+=i
            a1[1]+=j
            ans=min(ans, fn(a1)+abs(i)+abs(j))
            a1[0]-=i
            a1[1]-=j
    print(ans if ans!=PI else -1)