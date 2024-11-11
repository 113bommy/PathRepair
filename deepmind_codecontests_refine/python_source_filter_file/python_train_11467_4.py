def isvalid(d,li,m):
    if(d==0):
        return 0
    n=len(li)
    sumi=0
    for i in range(n):
        sumi+=max(0,li[i]-i//d)
    if(sumi>=m):
        return 1
    return 0
def binary_search(li,left,right,m):
    if(right<left):
        return 0
    mid=(left+right)//2
    if(isvalid(mid,li,m)):
        if(isvalid(mid-1,li,m)==0):
            return mid
        return binary_search(li,left,mid-1,m)
    return binary_search(li,mid+1,right,m)


l=input().split()
n=int(l[0])
m=int(l[1])
l=input().split()
li=[int(i) for i in l]
li.sort()
li.reverse()
if(sum(li)<m):
    print(-1)
else:
    print(binary_search(li,1,10**5+1,m))