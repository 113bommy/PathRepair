

t = int(input())
while t!=0:

    n = int(input())
    list1 = list(map(int,input().split()))
    p = max(list1)
    p1 = set(list1[:p])
    ans=list()
    if p1==set(range(1,p+1)):

        q1= set(list1[p:])

        if q1==set(range(1,n-p+1)):

            ans.append(p)

    p2 = set(list1[:n-p])
    if p2==set(range(1,n-p+1)):
        q2 = set(list1[n-p:])
        if q2==set(range(1,p+1)):

            ans.append(n-p)
    set(ans)
    print(len(ans))
    for i in (ans):
        print(i,n-i)




    t-=1