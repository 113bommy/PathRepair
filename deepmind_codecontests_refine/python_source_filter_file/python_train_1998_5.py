n, k = map(int, input().split())
m = list(map(int, input().split()))

ms = []
added = []
mss = set()

for i in range(n):
    if m[i] not in mss:
        if len(mss) == k:
            mss.remove(added[-k])
        mss.add(m[i])
        added.append(m[i])
        
a = added[:k]
a.reverse()
print(len(a))
print(*a)
             
    
            