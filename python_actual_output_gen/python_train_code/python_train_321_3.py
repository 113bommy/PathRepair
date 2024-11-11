N, K = map(int, input().split())
A = [int(i) for i in input().split()]
P=[0]*(N+1)
T=[0]*(N+1)
for i in range(N):
    P[i+1]=P[i]+A[i]
    if A[i]>=0:
        T[i+1]=T[i]+A[i]
    else:
        T[i+1]=T[i]
a=max(sum(P),0)
for i in range(K,N+1):
    t=P[i]-P[i-K]
    s=T[i-K]-T[0]
    u=T[N]-T[i]
    a=max(a,s+t+u,s+u)
    #print(a,s,t,u)
print(a)