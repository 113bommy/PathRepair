n, d = map(int, input().split())
daf = list(map(int, input().split()))

cand = set()

lim = 1e9
for x in daf:
    l = x - d
    r = x + d
    cand.add(l)
    cand.add(r)

#print(cand)
reject = set()

for x in cand:
    for y in daf:
        if y - d < x < y + d:
            reject.add(x)
            break
#print(reject)
print(len(cand - reject))
            
