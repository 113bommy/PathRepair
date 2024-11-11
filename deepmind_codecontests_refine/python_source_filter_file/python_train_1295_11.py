n,m = map(int,input().split())
d = {}
temp = []
for i in range(1,m+1):
    lb = i & (-i)
    if lb not in d:
        d[lb] = []
    d[lb].append(i)
    temp.append(lb)
temp=sorted(temp)
ans = []
for j in temp:
    if j <=n and len(d[j]):
        n -= j
        ans.append(d[j][-1])
        d[j].pop()
if n == 0:
    print(len(ans))
    print(*ans)
else:
    print(-1)