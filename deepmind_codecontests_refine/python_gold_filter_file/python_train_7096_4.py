def fillSorted(a,sector):
    for i in range(sector[0]-1,sector[1]-1,1):
        a[i]=1
    return a
def isUnsortable(a,sector):
    for i in range(sector[0]-1,sector[1]-1,1):
        if a[i]=='n':
            return True
    return False

n,m= map(int, input().split())
a=[]
for i in range(n):
    a.append('n')

sorted=[]
unsorted=[]
for i in range(m):
    t,l,r=map(int, input().split())
    if t:
        sorted.append([l,r])
    else:
        unsorted.append([l,r])


for sector in sorted:
    a=fillSorted(a,sector)
for sector in unsorted:
    if not(isUnsortable(a,sector)):
        print("NO")
        exit(0)
Ans=[1000]
for i in range(len(a)-1):
    if a[i]==1:
        Ans.append(Ans[i]+1)
    else:
        Ans.append(Ans[i]-1)
print("YES")
print(*Ans)
"""
print(sorted)
print(unsorted)      
print(a)
print(isUnsortable(a,unsorted[0]))"""
