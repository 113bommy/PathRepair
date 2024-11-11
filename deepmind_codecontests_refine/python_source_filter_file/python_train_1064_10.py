n = int(input())

check = [0 for i in range(n+1)]
nodes = []

for i in range(n-1):
    u,v = map(int,input().split())
    nodes.append((u,v))
    check[u]+=1
    check[v]+=1

left = 0; right = n-2
for u,v in nodes:
    if check[u]==1 or check[v]==1:
        print(left)
        left+=1
    else:
        print(right)
        right+=1
