def solve(n,a):
    tot=0
    for i in range(n):
        tot+=a[i]
    diffs = [] #alla suffix - prefix diffs[i]=prefix-suffix om delas innan element i
    diffs.append(-tot)
    for i in range(n):
        tot-=2*a[i]
        diffs.append(-tot)
        if tot==0:
            return ("YES")
    for i in range(n):
        diffmake=2*a[i]
        j=binary(diffs,diffmake)
        if j>=i and j!=-1:
            return ("YES")
        j=binary(diffs,-diffmake)
        if i>=j and j!=-1:
            return ("YES")
    return ("NO")


def binary(a,value):
    hi=len(a)
    lo=-1
    while (lo+1<hi):
        mi=(lo+hi)//2
        if a[mi]==value:
            return mi
        if a[mi]<value:
            hi=mi
        else:
            lo=mi
    return -1


n=int(input())
a = input().split()
for i in range (n):
    a[i]=int(a[i])
print(solve(n,a))
