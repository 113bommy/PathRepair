N=int(input())
A=[]
mod=10**9+7
for i in range(N):
    a=int(input())
    A.append((a,-1))
for i in range(N):
    a=int(input())
    A.append((a,1))
A.sort()
a=0
s=A[0][1]
ans=1
for i in range(2*N):
    if A[i][1]==s:
        a+=1
    else:
        ans*=a
        a%=mod
        a-=1
    if a==0 and i<2*N-1:
        s=A[i+1][1]
    #print(a,s,ans)
print(ans)