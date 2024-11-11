n = int(input())
d = {}
for i in range(n-1):
    u,v = map(int,input().split())
    try:
        d[u].append(v)
    except:
        d[u] = [v]
    try:
        d[v].append(u)
    except:
        d[v] = [u]
l = list(map(int,input().split()))
f = 0
i = 0
j = 1
while i < n  and j < n:
    if l[i] not in d[l[j]]:
        i = i + 1
    else:
        j = j + 1
if j != n and l[0] != 1: 
    print("No")
else:
    print("Yes")