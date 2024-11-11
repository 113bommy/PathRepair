from queue import Queue
n,m = map(int,input().split())
e = [[]for i in range(n+1)]
b = [0]*n
for i in range(m):
    u,v = map(int,input().split())
    e[u-1].append(v-1)
    e[v-1].append(u-1)
ans = 0
q = Queue()
a = input().split()
ai = [-1]*n
c=0
mask = [False]*n
for i in a:
    inti = int(i)
    ai[c] = inti
    if inti == 0:
        q.put(c)
        b[c]=1
    c+=1
T=[]
while not q.empty():
    i = q._get()
    ans+=1
    T.append(i+1)
    for j in e[i]:
        b[j]+=1
        if b[j]== ai[j]:
            q.put(j)

print(ans)
print(*T)

