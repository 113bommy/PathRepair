n=int(input())
A=list(map(int,input().split()))
ans=[]
for i in range(0,n-1):
    s=min(A[i:])
    y=A[i:]
    A[i],A[i+y.index(s)]=A[i+y.index(s)],A[i]
    ans.append(f'{i} {i+y.index(s)}')
print(len(ans))
for i in ans:
    print(ans)
    