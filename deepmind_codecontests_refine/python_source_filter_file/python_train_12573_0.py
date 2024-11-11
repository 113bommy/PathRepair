def cmb(n, r, mod):#コンビネーションの高速計算　
    if ( r<0 or r>n ):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod

mod = 10**9+7 #出力の制限
N = 50
g1 = [1, 1] # 元テーブル
g2 = [1, 1] #逆元テーブル
inverse = [0, 1] #逆元テーブル計算用テーブル

for i in range( 2, N + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )

N,K,T,S=map(int,input().split())
a=list(map(int,input().split()))

must0=[i for i in range(18) if S>>i &1==0]
must1=[i for i in range(18) if T>>i &1==1]

A=[]
for val in a:
    check=True
    for j in must0:
        check=check&(val>>j &1==0)
    for j in must1:
        check=check&(val>>j &1==1)
    if check:
        A.append(val)

if not A:
    print(0)
    exit()

bit=[]
for i in range(18):
    if i not in must0 and i not in must1:
        bit.append(i)

for i in range(len(A)):
    temp=0
    for j in range(len(bit)):
        temp+=(A[i]>>bit[j] &1==1)*2**j
    A[i]=temp

ans=0
n=len(bit)
for i in range(2**n):
    dic={}
    for a in A:
        val=a&i
        if val not in dic:
            dic[val]=0
        dic[val]+=1
    temp=0
    for val in dic:
        for j in range(1,min(K,dic[val])+1):
            temp+=cmb(dic[val],j,mod)
    popcount=0
    for j in range(n):
        popcount+=(i>>j &1)
    ans+=temp*(-1)**popcount

print(ans)