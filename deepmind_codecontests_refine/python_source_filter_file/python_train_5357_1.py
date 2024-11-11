p, q, l, r = map(int, input().split(' '))
c = [0]*1001
m = 0
for i in range(p):
    a, b = map(int, input().split(' '))
    m = max(a, b, m)
    for j in range(a, b+1):
        c[j] = 1

d = [0]*1001
for i in range(q):
    a, b = map(int, input().split(' '))
    for j in range(a, b+1):
        d[j] = 1

for i in range(0, l-1): d.pop(); d.insert(0, 0)

k = 0
#print(c[l:m+1])

for i in range(l, r+1):
    for j in range(i, m+1):
        if c[j] == 1 and d[j] == 1:
            k += 1
            break
    
    #print(d[l:m+1], k)
    d.pop()
    d.insert(0, 0)

print(k)