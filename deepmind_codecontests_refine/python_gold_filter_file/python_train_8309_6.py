N, Q = map(int, input().split())
if N == 1:
    for _ in range(Q):
        v, w = map(int, input().split())
        print(min(v, w))
else:
    L = [1]
    aa = 1
    def ch(k):
        return (k-2)//N+1
    
    def chh(a, b):
        if a == b:
            return a
        
        if a > b:
            a, b = b, a
        
        return chh(a, ch(b))
        
    for _ in range(Q):
        v, w = map(int, input().split())
        print(chh(v, w))
