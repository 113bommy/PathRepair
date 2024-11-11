def find_sort(d):
    l=list(d.keys())
    c=0
    while(c+1<len(l)):
        if d[l[c+1]][0]>d[l[c]][0]:
            (l[c+1],l[c])=(l[c],l[c+1])
            if c-1>=0:
                c-=2
        elif d[l[c+1]][0]==d[l[c]][0] and d[l[c+1]][1]<d[l[c]][1]:
            (l[c+1],l[c])=(l[c],l[c+1])
            if c-1>=0:
                c-=2
        c+=1
    return l
def check(l1,l2):
    if l1[0]==l2[0] and l1[1]==l2[1]:
        return True
    else:
        return False
 
 
(n,k)=(int(i) for i in list(str(input()).split(' ')))
d=dict()
for i in range(n):
    d.update({i:0})
for i in range(n):
    (p1,t1)=(int(i) for i in list(str(input()).split(' ')))
    d[i]=[p1,t1]
l=find_sort(d)
c=0
for i in range(n):
    if check(d[l[k-1]],d[i]):
        c+=1
print(c)