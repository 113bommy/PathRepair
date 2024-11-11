h,w,m = map(int,input().split())
x = {}
y = {}
dic = {}
for _ in range(m):
    a,b = map(int,input().split())
    dic[(a,b)] = 1
    x[a] = x.get(a,0) + 1
    y[b] = y.get(b,0) + 1
p = max(x.values())
q = max(y.values())
cnt = 1
a = [i for i in x if i == p]
b = [j for j in y if j == q]
for i in a:
    for j in b:
        if dic.get((i,j),-1) == -1:
            cnt = 0
            break
    if not cnt:
        break
print(p+q-cnt)