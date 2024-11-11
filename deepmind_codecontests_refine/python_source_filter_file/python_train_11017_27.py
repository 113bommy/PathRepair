N=int(input())
a=list(map(int,input().split()))

MAX=max(a)
MIN=min(a)
m=0
operation=[]
if abs(MAX)>=abs(MIN):
    n=a.index(MAX)
    for i in range(N):
        a[i]+=MAX
        m+=1
        operation.append([n+1,i+1])
    for i in range(N-1):
        a[i+1]+=a[i]
        m+=1
        operation.append([i+1,i+2])
else:
    n=a.index(MIN)
    for i in range(N):
        a[i]+=MIN
        m+=1
        operation.append([n+1,i+1])
    for i in range(N,0,-1):
        a[i-1]+=a[i]
        m+=1
        operation.append([i+1,i])

print(m)
for i in range(m):
    print(*operation[i])