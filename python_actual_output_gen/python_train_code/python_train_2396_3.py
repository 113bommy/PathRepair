n,m = [int(i) for i in input().split()]
seg = {i:[] for i in range(1,n+1)}
for j in range(m):
    a,b = [int(i) for i in input().split()]
    seg[a].append(b)
    seg[b].append(a)
tail = [0]*(n+1)
tail[1] = 1
for i in range(2,n+1):
    temp = [tail[j] for j in seg[i]]+[1]
    tail[i] = max(temp)+1
temp = [len(seg[i])*tail[i] for i in range(2,n+1)]
print(max(temp))