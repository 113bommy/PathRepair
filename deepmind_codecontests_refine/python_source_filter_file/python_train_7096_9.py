n, m = [int(i) for i in input().split()]

diff = [-1] * (n)
negs = []

for _ in range(m):
    t,l,r = [int(i) for i in input().split()]
    if t == 1:
        for i in range(l, r):
            diff[i] = 0
    else:
        negs.append((l,r))
for li, ri in negs:
    neg = False
    for i in range(li, ri):
        if diff[i] == -1:
            neg = True
            break
    if not neg:
        print("NO")
        import sys
        sys.exit()

arr = [0] 
for i in range(1, n):
    arr.append(arr[-1] + diff[i])
print("YES")
mn  = 1  - min(arr)
[print(a + mn, end=' ') for a in arr[:-1]]
print(arr[-1])
    
