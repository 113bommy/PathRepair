N=int(input())
t=[0]*N
for i in range(2,N+1):
    s=1
    while i>1:
        s+=1
        while i%s==0:
            i=i//s
            t[s-2]+=1
for j in range(N):
    q=q*(t[j]+1)%(10**9+7)
print(q)