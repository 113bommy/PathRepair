import sys
sys.setrecursionlimit(100000)

def dfs(v):
    global node_chk
    global edge_chk
    global B
    global connect
    global value

    node_chk[v] = 1
    connect[v] = value
    for x in B[v]:
        if(node_chk[x] == 0):
                dfs(x)



n,m = map(int,input().split())
B = [[]for i in range(n)] # 隣接リスト
edge_chk = [[]for i in range(n)]
node_chk = [0 for i in range(n)]
connect = [0 for i in range(n)]
value = 0

for i in range(m):
    A = list(map(int,input().split()))
    B[A[0]].append(A[1])
    B[A[1]].append(A[0])
    edge_chk[A[0]].append(0)
    edge_chk[A[1]].append(0)

for i in range(n):
    if(node_chk[i] == 1):
        continue
    dfs(i)
    value += 1


q = int(input())
for i in range(q):
    start,target = map(int,input().split())
    if(connect[start] == connect[target]):
        print("yes")
    else:
        print("no")
