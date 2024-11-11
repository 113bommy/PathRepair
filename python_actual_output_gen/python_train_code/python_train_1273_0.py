n, k = map(int,input().split())
m = list(map(int,input().split()))
t = {}
for i,e in enumerate(m):
    if i%k not in t:
        t[i%k] = e
    else:
        t[i%k] += e
mi = t[0]
mai = 1
for i in t:
    if mi>t[i]:
        ma = t[i]
        mai = i+1
print(mai)
