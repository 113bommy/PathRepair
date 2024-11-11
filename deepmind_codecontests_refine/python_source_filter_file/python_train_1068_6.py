for query in range(int(input())):
    nk=input().split()
    n=int(nk[0])
    k=int(nk[1])
    a=[int(x)-1 for x in input().split()]
    x=[False]*101
    count=0
    for y in range(n):
        x[a[y]]=True
    for y in range(101):
        if x[y]:
            count+=1
    if count!=1 and k==1:
        print(-1)
        continue
    if count==1 and k==1:
        print(1)
        continue
    if (count-1)%(k-1)==0:
        print((count-1)//(k-1))
    else:
        print((count-1)//(k-1)+1)
