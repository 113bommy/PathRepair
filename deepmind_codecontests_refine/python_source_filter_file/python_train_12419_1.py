try:
    a,b,c = map(int,input().split())
    arr1 = list(map(int,input().split()))
    arr2 = list(map(int,input().split()))
    arr3 = list(map(int,input().split()))
    mn = [min(arr1),min(arr2),min(arr3)]
    sm = [sum(arr1), sum(arr2), sum(arr3)]
    print(mn,sm)
    tot = sum(sm)
    x=min(min((mn[0]+mn[1]),(mn[1]+mn[2])),(mn[0]+mn[2]))
    ans=tot-2*x
    x=min(sm[0],min(sm[1],sm[2]))
    ans=max(ans,tot-2*x)
    print(ans)
except:
    pass