N,Q=map(int, input().split())
node_lst=[list(map(int, input().split())) for i in range(N-1)]
ope_lst=[list(map(int, input().split())) for i in range(Q)]
cnt_lst=[0 for i in range(N)]
for ope in ope_lst:
    p, x = ope[0], ope[1]
    cnt_lst[p-1]+=x
node_lst=sorted(node_lst, key=lambda x:x[0])
for l in node_lst:
    src, dst = l[0]-1, l[1]-1
    cnt_lst[dst]+=cnt_lst[src]
print(" ".join([str(c) for c in cnt_lst]))
