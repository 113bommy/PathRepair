def get(l,r,a):
    global A,B
    if len(a) == 0:
        return A
        
    if l == r:
        return len(a)*B
    
    m = (l+r)/2
    c,d = [],[]
    
    for x in a:
            if x <= m:
                c += [x]
            else:
                d += [x]
    return min(B*len(a)*(r-l+1), get(l,m,c)+get(m+1,r,d))
        

n,k,A,B = map(int,input().split())
a = list(sorted(list(map(int, input().split()))))
print(get(1, 1 << n, a))