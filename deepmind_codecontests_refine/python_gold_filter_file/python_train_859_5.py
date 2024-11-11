n = int(input())

d = list(map(int, input().split()))

l = []

while True:
    for i in range(n):
        a = d[i]
        for j in range(i + 1, n):
            if d[j] == a - 1:
                p = i, j
                break
        else:
            continue
        break
    else:
        break
    
    ai = i
    while ai + 1 < n and d[ai + 1] == d[ai] + 1:
        ai += 1
    
    nl = []
    if i != 0:
        nl.append(i)
    nl.append(ai - i + 1)
    nl.append(j - ai)
    if j != n - 1:
        nl.append(n - j - 1)

    l.append(nl)
    #print(*d[:i], '|', *d[i:ai + 1], '|', *d[ai+1:j + 1], '|', *d[j + 1:])
    d = d[j + 1:] + d[ai+1:j+1] + d[i:ai+1] + d[:i]
    
print(len(l))

for i in l:
    print(len(i), *i)
