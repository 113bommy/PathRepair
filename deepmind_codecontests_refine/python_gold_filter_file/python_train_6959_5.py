N=int(input())
ans=float('inf')

for i in range(1,int(N**0.5+1)):
    if N%i==0:
        ans=min(ans,len(str(N//i)))
print(ans)