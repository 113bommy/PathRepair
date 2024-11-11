n,m = map(int,input().split())
lst = [0]*m
if m%2:
    i = 1
    x = (m+1)//2
    lst[0] = x
    for j in range(x-1,0,-1):
        lst[i] = j
        i += 2
    i = 2
    for j in range(x+1,m+1):
        lst[i] = j
        i += 2
else:
    i = 0
    x = (m+1)//2
    for j in range(x,0,-1):
        lst[i] = j
        i += 2
    i = 1
    for j in range(x+1,m+1):
        lst[i] = j
        i += 2
t = n//m
if t==0:
    print(*lst[:n%m])
else:
    lst *= t
    lst += lst[:n%m]
    print(*lst)