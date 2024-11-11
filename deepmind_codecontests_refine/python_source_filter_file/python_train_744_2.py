

def check(p):
    n = len(p)
    res = 0
    for i in range(1,n):
        if abs(p[i]-p[i-1]) == 1: res +=1
    if abs(p[n-1] - p[0]) ==1: res +=1
    if res == n-1: return True
    return False

q = int(input())
for i in range(q):
    n = int(input())
    p = [int(s) for s in input().split(' ')]
    if check(p): print('YES')
    else: print('NO')