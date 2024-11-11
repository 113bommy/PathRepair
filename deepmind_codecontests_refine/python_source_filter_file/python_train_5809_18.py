import bisect
N,M=map(int,input().split())
A=list(map(int,input().split()))
A.sort()

#C[i]=パワーがi以下の人数
C=[0]*(10**5+1)
for a in A:
    C[a]+=1
for i in range(1,len(C)):
    C[i]+=C[i-1]

#和がx以上になる組み合わせの総数を求める関数
def pattern_num_ge_x(x):
    p=0
    for a in A:
        p+=(N-(C[x-a-1] if x-a-1>=0 else 0))
    return(p)

#pattern_num_ge_x(x)がM未満になる最小のxを探す(=r)
#lはM以上になる最大のx
l=-1
r=10**5*2+1
while r-l>1:
    m=(r+l)//2
    if pattern_num_ge_x(m)<M:
        r=m
    else:
        l=m

#和がr以上になる組み合わせの総和を求める(累積和を使用)
S=[0]+list(reversed(A[:]))
for i in range(1,N+1):
    S[i]+=S[i-1]
ans=0
for a in A:
    idx=bisect.bisect_left(A,r-a)
    ans+=a*(N-idx) + S[N-idx]
    M-=(N-idx)

#回数のあまり分lを足す
ans+=l*M

print(ans)