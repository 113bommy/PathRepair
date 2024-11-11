n, m = map(int,input().split())
l, t1 = [], {i:0 for i in range(105)}
for _ in range(m):
    l1 = list(map(int,input().split()))
    l.append(l1)
    tp =max(l1)
    ls = l1.index(tp)
    if ls not in t1:
        t1[ls] = 1
    else:
        t1[ls]+=1
# print(t1)
res = 0
for i in range(1,n+1):
    if t1[res]<t1[i]:
        res = i
print(res+1)
# print(max(t1,key=lambda s:t1[s]))