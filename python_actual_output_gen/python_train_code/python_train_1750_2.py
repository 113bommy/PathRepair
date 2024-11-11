def binary(arr,val):
    l,r = 0,len(arr)-1
    while l<r:
        m = (l+r)//2
        if val>=arr[m][0] and val<=arr[m][1]:
            return m
        elif val>arr[m][1]:
            l = m
        else:
            r = m
        if r-l==1:
            break
    if arr[r][0]<=val and val<=arr[r][1]:
        return r
    else:
        return l
n,m = list(map(int,input().split()))
dom = list(map(int,input().split()))
q = list(map(int,input().split()))
for i in range(1,n):
    dom[i]+= dom[i-1]
arr = [[0,dom[0]]]
for i in range(1,len(dom)):
    arr.append([dom[i-1],dom[i]])
for i in q:
    pos = binary(arr,i)
    print(pos+1,i-arr[pos][0])