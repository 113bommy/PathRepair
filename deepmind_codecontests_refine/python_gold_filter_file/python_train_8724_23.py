N,M=map(int,input().split())
A=set(range(1,M+1))
for i in range(N):
    k,*a=map(int,input().split())
    A&=set(a)
print(len(A))