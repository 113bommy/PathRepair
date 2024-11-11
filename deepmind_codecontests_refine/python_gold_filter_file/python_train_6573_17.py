n, k = input().split()

n = int(n)
k = int(k)

d = []
d.extend(input().split())

db = 0
nd = []
ndb = {}

for i in range(len(d)):
    d[i] = int(d[i])
    if d[i] % k == 0:
        db += 1
    else:
        if (d[i] % k) in ndb:
            ndb[d[i] % k] += 1
        else:
            ndb[d[i] % k] = 1
            nd.append(d[i] % k)

result = 2 * int(db / 2)

for i in range(len(nd)):
    if k == (nd[i] * 2):
        result += 2 * int(ndb[nd[i]] / 2)
    else:
        if (k - nd[i]) in nd:
            result += min(ndb[nd[i]], ndb[k-nd[i]])
print (result)
