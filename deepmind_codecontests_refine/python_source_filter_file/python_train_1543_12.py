import sys
sys.setrecursionlimit(20000)
N, M = [int(i) for i in input().split()]
parent = [i for i in range(N+1)]
node_num = [1 for i in range(N+1)]
def find(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]

bridge = []
for i in range(M):
    A, B = [int(i) for i in input().split()]
    bridge.append([A, B])

bridge = bridge[::-1]
ans_rev = [N*(N-1)//2]
combi = 0
for i in range(M-1):
    A, B = bridge[i]
    r_A = find(A)
    r_B = find(B)
    if r_A != r_B:
        parent[r_B] = r_A
        combi += node_num[r_B] * node_num[r_A]
        node_num[r_A] += node_num[r_B]
    ans_rev.append(N*(N-1)//2-combi)

ans = ans_rev[::-1]
print(*ans, sep="\n"