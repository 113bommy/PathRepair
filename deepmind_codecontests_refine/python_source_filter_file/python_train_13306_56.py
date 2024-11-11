L=int(input())

p=[1]*21
N=0
for i in range(20):
    p[i+1]=p[i]*2
    if p[i+1]>L:
        N=i+1
        break

        
ans=[]
M=0
for i in range(N-1):#2の累乗
    ans.append([i+1,i+2,0])
    ans.append([i+1,i+2,p[i]])
    M+=2
    
path=L-p[N-1]#２進数表記でbitが1なら終点への辺を足す
N2=len(bin(path))-2    


#途中の頂点から終点まで
for i in range(N):
    if path&1 ==1:
        ans.append([i+1,N,L-p[i]+1])
        M+=1
        L-=p[i]
    path=path>>1
    
print(' '.join(map(str, [N,M])))
for i in range(M):
    print(' '.join(map(str, ans[i])))