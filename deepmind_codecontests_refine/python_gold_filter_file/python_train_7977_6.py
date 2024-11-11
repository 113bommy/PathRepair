import sys

input = sys.stdin.readline


############ ---- Input Functions ---- ############
def inp():
    return (int(input()))


def inlt():
    return (list(map(int, input().split())))


def insr():
    s = input()
    return (list(s[:len(s) - 1]))


def invr():
    return (map(int, input().split()))

def explore(adj,i):
    count=[]
    q=[i]
    while(q!=[]):
        i=min(q)
        q.remove(i)
        if visited[i]!=1:
            visited[i]=1
            count+=[i+1]
            q+=adj[i]
    return count

x=0
n=inp()
adj=[[] for i in range(n)]
for i in range(n-1):
    u=inp()
    if u !=-1 and u-1!= i+1:
        adj[u-1].append(i+1)

for i in range(n):
    if adj[i]==[]:
        continue
    else:
        a=0
        for j in adj[i]:
            if adj[j]==[]:
                a+=1
        if a<3:
            x=1
            break

if x==1:
    print("NO")
else:
    print("YES")








