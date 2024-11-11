i,o,t,j,l,s,z=map(int, input().split())
ans=o+j//2*2+l//2*2+i//2*2+(i&1 and j&1 and l&1)*3
k=min(i,j,l)
for n in range(max(0,k-10),k+1):
    ans=max(ans,o+k*3+(i-k)//2*2+(j-k)//2*2+(l-k)//2*2)
print(ans)