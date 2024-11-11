n,k = [int(i) for i in input().split()]
maxim = -9999999
for i in range(0,n):
    ls = [int(i) for i in input().split()]
    if ls[1]>k:
        maxim = (max(ls[0]-(ls[1]-k),maxim))

    else:
        maxim = max(maxim,ls[0])


print(maxim)