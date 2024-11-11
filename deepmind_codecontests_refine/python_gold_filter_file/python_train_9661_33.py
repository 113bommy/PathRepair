N=int(input())
A=sorted(map(int,input().split()))
m,M=A[0],A[-1]
L=[]

for i in range(1,N-1):
    v=A[i]
    if v>=0:
        L.append((m,v))
        m-=v
    else:
        L.append((M,v))
        M-=v
L.append((M,m))
ans=M-m

print(ans)
for a,b in L:
    print(a,b)