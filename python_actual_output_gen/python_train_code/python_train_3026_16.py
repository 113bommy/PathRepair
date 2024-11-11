n=int(input())
ans=[]
i=1
nn=n**n
for _ in range(n):
    s=[]
    for _ in range(n//2):
        s+=[str(i)]
        s+=[str(nn-i+1)]
        i+=1
    ans+=[' '.join(s)]
print('\n'.join(ans))