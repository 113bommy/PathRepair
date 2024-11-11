n,m,k = list(map(int,input().split()))
p = list(map(int,input().split()))
s =  list(map(int,input().split()))
c =  list(map(int,input().split()))
d = {}
for i in range(n):
    if s[i] not in d:
        d[s[i]] = p[i]
    else:
        if d[s[i]] < p[i]:
            d[s[i]] = p[i]
count = 0
for k in c:
    if p[k-1] not in d.values():
        count += 1
print(count)