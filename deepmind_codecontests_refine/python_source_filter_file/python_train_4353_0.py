N,que=int(input()),[]
for i in range(N):
    s,p=list(input().split())
    que.append((s,int(p),i+1))
que.sort()
for x in que:
    print(x[-1])