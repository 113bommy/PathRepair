n,m = map(int, input().split())
t = [0] * (m+1)

def build(l, r):
    if l == r:
        t[l] = 1
        return
    mid = (l+r) // 2
    build(l, mid)
    build(mid+1, r)

def insert(l, r):
    if l == r:
        t[l] += 1
        return
    mid = (l+r) // 2
    insert(l,mid)
    insert(mid+1,r)

build(1, m)
for _ in range(n):
    l,r = map(int, input().split())
    insert(l,r)
res = []
for i in range(len(t)):
    if t[i] == 1:
        res.append(i)
print(len(t))
print(''.join(map(str,res)))