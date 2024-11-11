def incon(a):
    n=len(a)
    su=0
    for i in range(n):
        for j in range(i+1,n):
            su=su+abs(a[i]-a[j])
    return su
for i in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if sum(a)%len(a)==0:
        print(0)
    else:
        su=sum(a)
        k=su%(n-1)
        print(k*(n-k))