n,x = map(int, input().split())
m = list(map(int, input().split()))
ind = 0
for i in range(n):
    if(m[ind]<m[i]):
        ind = i
z = m[ind]
r = m[0]
ans = []
l = []
for i in range(ind):
    ans.append([r,m[i+1]])
    l.append(min(m[i+1],r))
    if(r<m[i+1]):
        r = m[i+1]
for i in range(ind+1, n):
    l.append(m[i])
for i in range(x):
    q = int(input())
    if(q<=ind):
        print(ans[q-1][0], ans[q-1][1])
    elif(q>=n):
        print(z, l[(q-n)%(n-1)])
    else:
        print(z, m[q])
