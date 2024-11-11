import sys
def mapi(): return map(int,input().split())
def maps(): return map(str,input().split())
#--------------------------------------------------

for _ in range(int(input())):
    n,k,d = mapi()
    a = list(mapi())
    mp = {}
    for i in range(d):
        try:
            mp[a[i]]+=1
        except KeyError:
            mp[a[i]]=1
    res = len(mp)
    i = 1
    j = d
    while i<n and j<n:
        try:
            mp[a[j]]+=1
        except:
            mp[a[j]]=1
        if mp[a[i-1]]==1:
            del mp[a[i-1]]
        else:
            mp[a[i-1]]-=1
        i+=1
        j+=1
        res = min(res, len(mp))
        print(i,j)
    print(res)
