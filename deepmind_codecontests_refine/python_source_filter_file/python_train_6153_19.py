def kuzn(n1,d1,x1,y1):
    if x1 > n1 or y1 > n1:
        return 0
    elif x1 == n1:
        if y1 == n1 - d1:
            return 1
        else:
            return 0
    elif y1 == n1:
        if x1 == n1 - d1:
            return 1
        else:
            return 0
    if y1 + x1 < d1:
        return 0
    if y1 + x1 == d1:
        return 1
    if y1 - x1 > d1:
        return 0
    if y1 - x1 == d1:
        return 1
    if x1 - y1 > d1:
        return 0
    if x1 - y1 == d1:
        return 1
    if y1 + x1 > 2*n1 + d1:
        return 0
    return 1
    
n, d = [int(i) for i in input().split()]
for j in range(int(input())):
    x, y = map(int,input().split())
    print('YES' if kuzn(n,d,x,y) else 'NO')