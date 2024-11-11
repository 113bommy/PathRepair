n=int(input())
total=[]
for i in range(n):
    dishes=int(input())
    a=[int(x) for x in input().split()]
    b=[int(x) for x in input().split()]
    l1=sorted(zip(a,b))
    pickup=sum(b)
    mintime=pickup
    for t in l1:
        pickup-=t[1]
        mintime=min(mintime,max(t[0],pickup))
    total.append(mintime)
for k in total:
    print(k)