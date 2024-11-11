N = list(map(int, input().split()))
d = {0:1}

pos=[]
for x in range(N[0]):
    a = list(map(int, input().split()))
    for y in pos:
        key = (a[0]-y[0])*(10**11)+(a[1]-y[1])
        if key<0:
            key=-key
        if key not in d.keys():
            d[key] = 0
        d[key] += 1
    pos.append(a)
    
print(N[0]-max(d.values()))