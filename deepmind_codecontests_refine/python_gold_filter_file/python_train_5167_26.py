from math import ceil
s=input()
def isgood(k):
    d={}
    q=set(s[:k])
    for x in range(26):
        d[chr(x+ord('a'))]=0
    for x in range(k):
        d[s[x]]+=1
    for x in range(k,len(s)):
        d[s[x-k]]-=1
        d[s[x]]+=1
        tmp=q.copy()
        for y in q:
            if d[y]==0:
                tmp.remove(y)
        q=tmp
        if len(q)==0:
            break
    return len(q)>0
l=0
r=len(s)
while r-l>1:
    mid=ceil((r+l)/2)
    if isgood(mid):
        r=mid
    else:
        l=mid
print(r)