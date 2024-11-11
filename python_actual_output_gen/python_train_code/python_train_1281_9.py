N,P,Q,R=map(int,input().split())
arr = list(map(int,input().split()))
l = float('-inf')
#PSUM
Pmax=[0]*N
Pmax[0]=P*arr[0]
for i in range(1,N):
    Pmax[i]=max(Pmax[i-1],P*arr[i])
#SSum
Smax=[0]*N
Smax[0]=R*arr[N-1]
for j in range(N-1,0,-1):
    Smax[j]=max(R*arr[j],Smax[j])
for i in range(0,N):
    l=max(l,Pmax[i]+Q*arr[i]+Smax[i])
print(l)
                    
            
            
