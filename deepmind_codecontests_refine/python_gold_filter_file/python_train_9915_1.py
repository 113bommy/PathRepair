t=int(input())
for i in range(t):
    l=1
    ans=0
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    b=[0]*n
    for j in range(1,n-1):
        if a[j-1] < a[j] > a[j+1]:
            b[j] = 1
    # print(b)
    temp=b[1:1+k-3].count(1)
    # print(temp)
    ans=temp
    for j in range(1,n-k+2):
        temp+=b[j-1+k-2]
        temp-=b[j-1]
        # print(b[j-1+k-2],b[j-1],j-1+k-2)
        if ans<temp:
            ans=temp
            l=j
    print(ans+1,l)
    