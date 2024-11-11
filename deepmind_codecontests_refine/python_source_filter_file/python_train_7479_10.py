import bisect
#####segfunc######                                                              
def segfunc(x,y):
    return x+y

def init(init_val):
    #set_val                                                                    
    for i in range(n):
        seg[i+num-1]=init_val[i]
    #built                                                                      
    for i in range(num-2,-1,-1):
        seg[i]=segfunc(seg[2*i+1],seg[2*i+2])
    
def update(k,x):
    k+=num-1
    seg[k]=x
    while k+1:
        k=(k-1)//2
        seg[k]=segfunc(seg[k*2+1],seg[k*2+2])

def query(p,q):
    if q<=p:
        return ide_ele
    p+=num-1
    q+=num-2
    res=ide_ele
    while q-p>1:
        if p&1==0:
            res=segfunc(res,seg[p])
        if q&1==1:
            res=segfunc(res,seg[q])
            q-=1
        p=p//2
        q=(q-1)//2
    if p==q:
        res=segfunc(res,seg[p])
    else:
        res=segfunc(segfunc(res,seg[p]),seg[q])
    return res

ide_ele=0
n,k=map(int,input().split())
num=2**(n).bit_length()
seg=[ide_ele]*2*num
a=[]
for i in range(n):
    p=int(input())
    a.append(p-k)
d=[0]
for i in range(n):
    d.append(d[-1]+a[i])
b=sorted(d)
a=[]
for i in d:
    p=bisect.bisect_left(b,i)
    a.append(p)
#init(p)
ans=0
a.reverse()
update(a[0],1)
for i in range(n):
    ans+=query(a[i+1],n)
    update(a[i+1],query(a[i+1],a[i+1]+1)+1)
print(ans)
#query(0,i)

exit()
