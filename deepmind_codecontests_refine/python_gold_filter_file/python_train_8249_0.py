t = int(input())

for _ in range(t):
    l = int(input())
    a = input().rstrip()
    b = input().rstrip()
    
    ans = []
    c = 0
    if a[0]=='1':
        c += 1
    
    for i in range(len(a)-1):
        if a[i+1] != a[i]:
            ans.append(i+1)
            c+= 1
            
    bns = []
    d = 0
    if b[0]=='1':
        d += 1
    
    for i in range(len(b)-1):
        if b[i+1] != b[i]:
            bns.append(i+1)
            d += 1
            
    if c%2!=d%2:
        ans += [l]
    f = ans + bns[::-1]
    print(len(f), *f)