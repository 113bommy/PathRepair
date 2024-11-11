N,K=map(int,input().split())
p=list(map(int,input().split()))
a=0
for j in range(K):
    a+=(1+p[j])/2
Max=a
for i in range(K-1,N):
    a=a+(p[i]-p[i-K+1])/2
    if Max<a:
        Max=a
print(Max)