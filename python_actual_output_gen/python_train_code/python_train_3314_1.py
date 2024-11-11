import sys
input = sys.stdin.readline
n=int(input())
p=list(map(int,input().split()))
pr=list(map(int,input().split()))
x=[]
for i in range(5):
    x.append([pr[i],i])
pr.sort()
x.sort()
s=0
ans=[0]*5
for i in range(n):
    s=s+p[i]
    for j in range(4,-1,-1):
        if s>=pr[j]:
            f=pr[j]//s
            s=s-f*pr[j]
            ans[x[j][1]]+=f
print(*ans)
print(s)