#segtree ライブラリ
#BITライブラリの作成
#リストの要素を1,0で長さをｎとした時に使える
class BIT:
    def __init__(self,n):
        self.n=n
        self.data=[0]*(n+1)
    def to_sum(self,i):
        s=0     
        while i>0:
            s+=self.data[i]
            i-=(i& -i)
        return s
    def add(self,i,x):
        while i<=self.n:
            self.data[i]+=x
            i+=(i & -i)
    def get(self,i,j):
        return self.to_sum(j)-self.to_sum(i-1)
n=int(input())
s=list(input())
q=int(input())
que=[]

for i in range(q):
    p=list(input().split())
    que.append(p)
alpha="abcdefghijklmnopqrstuvwxyz"
segtree={alpha[i]:BIT(n) for i in range(26)}  
for i in range(n):
    segtree[s[i]].add(i+1,1)
for q in que:
    x,y,z=q[0],q[1],q[2]
    if int(x)==1:
        #y文字目をzに変更する
        y=int(y)  
        for i in range(26):
            if segtree[alpha[i]].get(y,y)==1:
                segtree[alpha[i]].add(y,-1)
                break
        segtree[z].add(y,1)
    else:
        ans=0
        for i in range(26):
            if segtree[alpha[i]].get(int(y),int(z))>0:
                ans+=1
        print(ans)       
