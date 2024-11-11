N,K=map(int,input().split())
A=list(map(int,input().split()))
A=[0]+A
for i in range(N):
    A[i+1]+=A[i]
B=[]
for i in range(1,N+1):
    for j in range(N-i+1):
        B.append(A[i+j]-A[j])
B.sort(reverse=True)
m=40
x=0
for t in range(m,0,-1):
    res=0
    for a in B:
        if ((x+1<<(t-1))&a)==(x+1<<(t-1)):
            res+=1
        if res>=K:
            x+=1<<(t-1)
            break
print(x)
