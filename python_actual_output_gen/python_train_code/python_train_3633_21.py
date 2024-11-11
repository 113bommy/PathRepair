def cyclic_shift(a, b, k):
    global s
    if a == b:
        return
    
    k = k % (b - a)
    if k == 0:
        return
    
    p = s[a-1:b]
    p.reverse()
    
    pl = p[:k]
    pl.reverse()
    
    pr = p[k:]
    pr.reverse()

    s[a-1:b] = pl + pr


s = list(input())

for i in range(int(input())):
    q = list(map(int, input().split()))
    cyclic_shift(q[0], q[1], q[2])
    
print (''.join(s))