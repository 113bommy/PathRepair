N,K=map(int,input().split())
A=[0]+list(map(int,input().split()))
T={}
T[1]=1
t=1
for i in range(2,K+1):
    a=A[t]
    t=a
    K-=1
    if a in T:
        l=list(T.keys())[T[a]-1:]
        print(l[K%len(l)])
        break
    else:
        T[a]=i
else:
    print(A[t])