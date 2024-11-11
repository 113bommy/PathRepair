import sys
sys.setrecursionlimit(3000)

n=int(input())
m=[[] for i in range(n)]
for i in range(n-1):
    a,b,c=map(int, input().split())
    m[a-1].append([b-1,c])
    m[b-1].append([a-1,c])
q,k=map(int, input().split())
    
def reach(m,d,k):
    for i in m[k]:
        if d[i[0]]==-1:
            d[i[0]]=d[k]+i[1]
            reach(m,d,i[0])
d=[-1]*n
d[k-1]=0
reach(m,d,k-1)

for i in range(q):
    x,y=map(int, input().split())
    print(d[x-1]+d[y-1])