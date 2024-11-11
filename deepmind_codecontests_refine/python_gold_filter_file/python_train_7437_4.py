n,k,p=map(int,input().split())
oc,ec=[],[]
for i in map(int,input().split()):
    if i&1:
        oc.append(i)
    else:ec.append(i)
l=len(oc)
if l<k-p or l&1!=(k-p)&1 or  len(ec)+(l-(k-p))/2<p:
    print('NO')
    exit()
res=[]
q=k-p
while p:
    if len(ec):
        res.append([ec.pop()])
    elif len(oc)>=2:
        res.append(oc[-2:])
        del oc[-2:]
    else:
        print('NO')
        exit(0)
    p-=1
while q:
    if len(oc):
        res.append([oc.pop()])
    else:print('NO');exit(0)
    q-=1
if len(ec):
    res[0]+=ec
if len(oc)%2==0:
    res[0]+=oc

print('YES')
for s in res:
    print(len(s),*s)