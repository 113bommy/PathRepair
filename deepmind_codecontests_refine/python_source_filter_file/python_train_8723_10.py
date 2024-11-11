N=int(input())
A=[int(_) for _ in input().split()]
ans=[0]*N
ans[0]=sum(A)//2-sum(A[1::2])
for i in range(N-１):
    ans[i+1]=A[i]-ans[i]
print(' '.join(str(2*a) for a in ans))