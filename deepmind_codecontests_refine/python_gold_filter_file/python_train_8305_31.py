n = int(input())
p = list(map(int,input().split()))

def init(init_val):
    #set_val
    for i in range(n):
        seg[i+num-1]=init_val[i]    
    #built
    for i in range(num-2,-1,-1) :
        seg[i]=max(seg[2*i+1],seg[2*i+2]) 
    
def update(k,x):
    k += num-1
    seg[k] = x
    while k+1:
        k = (k-1)//2
        seg[k] = max(seg[k*2+1],seg[k*2+2])
    
def query(p,q):
    if q<=p:
        return ide_ele
    p += num-1
    q += num-2
    res=ide_ele
    while q-p>1:
        if p&1 == 0:
            res = max(res,seg[p])
        if q&1 == 1:
            res = max(res,seg[q])
            q -= 1
        p = p//2
        q = (q-1)//2
    if p == q:
        res = max(res,seg[p])
    else:
        res = max(max(res,seg[p]),seg[q])
    return res

#####単位元######
ide_ele = -1

#num:n以上の最小の2のべき乗
num =2**(n).bit_length()
seg=[ide_ele]*2*num

res = 0
s = [0]*(n+1)

update(p[0],0)
for i in range(1,n):
    k1 = query(p[i],n+1)
    if k1 != -1:
        update(p[k1],-1)
        k2 = query(p[i],n+1)
        s[i] = p[i]*(k1-k2) + s[k1]
        res += s[i]
        update(p[k1],k1)
    update(p[i],i)


ide_ele = -n
seg=[ide_ele]*2*num

s = [0]*(n+1)

update(p[-1],1-n)
for i in range(n-2,-1,-1):
    k1 = query(p[i],n+1)
    if k1 != -n:
        update(p[-k1],-n)
        k2 = query(p[i],n+1)
        s[i] = p[i]*(k1-k2)+s[-k1]
        res += s[i]
        update(p[-k1],k1)
    update(p[i],-i)

print(res)