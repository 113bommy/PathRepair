import math,io,os,sys
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# sys.stdout.write(str(x) + "\n")

def rindex(lst, value):
    lst.reverse()
    i = lst.index(value)
    lst.reverse()
    return len(lst) - i - 1

t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    
    sor=sorted(a)
    if a==sor:
        print(0)
        continue
    # print("sor", sor)

    for i in range(1,999999):
        if i%2:
            for j in range(0,n-1,2):
                if a[j]>a[j+1]:
                    a[j],a[j+1]=a[j+1],a[j]
        else:
            for j in range(1,n,2):
                if a[j]>a[j+1]:
                    a[j],a[j+1]=a[j+1],a[j]
        if a==sor:
            break
    print(i)

    # mx=0
    # for ind, i in enumerate(a):
    #     ind1=sor.index(i)
    #     # print("ind1", ind1)
    #     ind2=rindex(sor,i)
    #     # print("ind2", ind2)
    #     q=min(abs(ind-ind1),abs(ind-ind2))
    #     mx=max(q,mx)
    # print(mx)
