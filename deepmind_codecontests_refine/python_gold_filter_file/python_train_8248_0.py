t=int(input())
for _ in range(t):
    n=int(input())
    l=[int(x) for x in input().split()]
    mx=max(l)
    d=set()
    for ele in l:
        d.add(ele)
    flag=False
    for i in range(1,1025,1):
        j=0
        while(j<n):
            xor=i^l[j]
            if xor in d:
                d.remove(xor)
            else:
                break
            j+=1
        if j==n:
            flag=True
            break
        for ele in l:
            d.add(ele)
    if flag==True:
        print(i)
    else:
        print(-1)