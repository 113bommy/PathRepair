import sys
 
n,m = [int(x) for x in input().split()]
X = [int(x) - 1 for x in input().split()]
 
s = 0
right = [[] for _ in range(n)]
left = [[] for _ in range(n)]
for j in range(m - 1):
    a,b = X[j], X[j + 1]
    if a == b:
        continue
    if a > b:
       a,b = b,a 
    right[a].append(b)
    left[b].append(a)
    s += b - a
 
out = [s]
for i in range(1, n): 
    for b in right[i - 1]:
        s -= b
    for b in left[i - 1]:
        s -= b + 1
 
    for b in right[i]:
        s -= b - i
    for b in left[i]:
        s -= i - b - 1
    
    for b in right[i]:
        s += b
    for b in left[i]:
        s += b + 1
 
    for b in right[i - 1]:
        s += b - (i - 1) - 1
    for b in left[i - 1]:
        s += (i - 1) - b
    out.append(s)
print (' '.join(str(x) for x in out))