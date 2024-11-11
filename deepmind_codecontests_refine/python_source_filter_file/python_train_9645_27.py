N=int(input())
s=list(map(int,input().split()))
x=[None]*600
cnt=0
for i in range(N):
    c=s[i]
    if c: x[c]=1
for i in range(1,N):
 if x[i]==1: cnt+=1
print(cnt)