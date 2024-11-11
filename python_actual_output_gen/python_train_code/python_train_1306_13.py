n,t=map(int,input().split())
queue=list(input().strip())
cpqueue=queue.copy()
for j in range(t):
    for i in range(1,n):
        if queue[i-1]=='B' and queue[i]=='G':
            cpqueue[i-1],cpqueue[i]=cpqueue[i],cpqueue[i-1]
    queue=cpqueue.copy()
print(cpqueue)    