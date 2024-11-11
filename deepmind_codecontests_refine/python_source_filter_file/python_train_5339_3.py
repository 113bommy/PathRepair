t=int(input())
for i in range(t):
    n=int(input())
    l=list(map(int, input().split()))
    li=[]
    e=0
    for j in range(1, n):
        if l[j]>l[j-1]:
            e+=1
        else:
            li.append(e)
            e=1
        if j==n-1:
            li.append(e)
    prev=0
    ind=1
    h=0
    while ind<=len(li):
        h+=1
        ass=sum(li[prev:ind])
        prev=ind
        ind+=ass
    print(h)