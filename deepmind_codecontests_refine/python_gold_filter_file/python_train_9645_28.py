N=int(input())
s=list(map(int,input().split()))
x=[None]*605
cnt=0
for i in range(N):
    c=s[i]
    if c: x[c]=1
for i in range(1,601):
 if x[i]==1: cnt+=1
print(cnt)