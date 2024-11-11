n,k = map(int,input().split())
alist = list(map(int,input().split()))
memo = []
p = 1
vis = ['.']*n
while vis[p-1] == '.':
    memo.append(p)
    vis[p-1] = 'v'
    p = alist[p-1]
 
loop = memo.index(p)
if k < len(memo):
    print(memo[k])
else:
    print(memo[loop+(k-loop)%(len(memo)-loop)])