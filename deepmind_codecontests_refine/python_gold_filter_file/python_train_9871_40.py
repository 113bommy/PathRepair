# dp[i][j]=(i番目まで使って最後の高さがjであるようなものの美しさの最大値)
# dp[i][j]=max(dp[i-1][k])+a[i](h[i]==j,0<=k<j),dp[i-1][j](otherwise)

def segfunc(x,y):
    return max(x,y)


def init(init_val):
    #set_val
    for i in range(n):
        seg[i+num-1]=init_val[i]    
    #built
    for i in range(num-2,-1,-1) :
        seg[i]=segfunc(seg[2*i+1],seg[2*i+2]) 
    
def update(k,x):
    k += num-1
    seg[k] = x
    while k:
        k = (k-1)//2
        seg[k] = segfunc(seg[k*2+1],seg[k*2+2])
    
def query(p,q):
    if q<=p:
        return ide_ele
    p += num-1
    q += num-2
    res=ide_ele
    while q-p>1:
        if p&1 == 0:
            res = segfunc(res,seg[p])
        if q&1 == 1:
            res = segfunc(res,seg[q])
            q -= 1
        p = p//2
        q = (q-1)//2
    if p == q:
        res = segfunc(res,seg[p])
    else:
        res = segfunc(segfunc(res,seg[p]),seg[q])
    return res


N=int(input())
h=list(map(int,input().split()))
a=list(map(int,input().split()))
n=N+1
#####単位元######
ide_ele = 0 #変える
num =2**(n-1).bit_length()
seg=[ide_ele]*2*num
dp=[0]*n
init(dp)
for i in range(N):
    # dp[h[i]]の値をdp[k](kは[0,h[i]))の最大値+a[i]にする
    # 手で書いてみると動きがわかりやすい
    update(h[i],query(0,h[i])+a[i])
print(query(0,n))