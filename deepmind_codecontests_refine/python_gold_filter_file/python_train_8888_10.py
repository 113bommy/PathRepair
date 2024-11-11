from collections import defaultdict
n = int(input())
a = []
b = []
for _ in range(n):
    x,y = map(int,input().split())
    a.append(x)
    b.append(y)

s = defaultdict(int)
for i in a:
    s[i]+=1

d = set()
op = 0
for i in range(n):
    if a[i]!=b[i]:
        if b[i] in s and b[i] not in d:
            op += s[b[i]]
            d.add(b[i])
    else:
        if s[b[i]]>1:
            if b[i] not in d:
                op += s[b[i]]-1
                d.add(b[i])
            else:
                op+=1
print(max(n-op,0))
