X,N=map(int,input().split())
p=list(map(int,input().split()))

Q=[0]*101
for i in range(101):
    Q[i]=abs(X-i)


for i in  p:
    Q[i]=1000

print(Q.index(min(Q)))