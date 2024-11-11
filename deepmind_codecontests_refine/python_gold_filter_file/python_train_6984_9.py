n,m = [int(x) for x in input().split()]
L = []
for _ in range(n):
    L.extend([i for i in input()])
    
for i in range(n*m):
    if L[i] == '.':
        L[i] = 0
    else:
        L[i] = 1
stars = []
for i in range(n*m):
    l = 0
    y = i//m
    x = i%m
    if L[i] == 1:
        while True:
            if (y+l != n-1) and ((y-l) != 0) and (x-l != 0) and (x+l != m-1):
                l += 1
                if L[i+l]*L[i-l]*L[i-l*m]*L[i+l*m] == 0:
                    l -= 1
                    break
            else:
                break
        if l > 0:
            stars.append((i,l))
T = [0]*(n*m)
for s in stars:
    T[s[0]] = 1
    for l in range(1,s[1]+1):
        T[s[0]+l] = 1
        T[s[0]-l] = 1
        T[s[0]-l*m] = 1
        T[s[0]+l*m] = 1
if T == L:
    print(len(stars))
    for s in stars:
        print(1+(s[0]//m),1+(s[0]%m),s[1])
else:
    print(-1)