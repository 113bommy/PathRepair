test=int(input())
for i in range(test):
    n=int(input())
    ls=list(map(int, input().split()))
    d={}
    for j in range(n):
        if ls[j] in d.keys():
            d[ls[j]]=d[ls[j]]+1
        else:
            d[ls[j]]=1
    k=set()
    s=0
    for key,value in d.items():
        while value in k and value>0:
            value=value-1
        k.add(value)

    print(str(sum(k)))
    