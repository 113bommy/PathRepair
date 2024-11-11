N,M=map(int,input().split())
S=(range(1,M+1))
for i in range(N):
    K,*A=map(int,input().splirt())
    S&=set(A)
print(len(S))