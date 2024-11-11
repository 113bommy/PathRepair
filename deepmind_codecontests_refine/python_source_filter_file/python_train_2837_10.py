t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        a.append(list(map(int, input().split())))
        
    l, r = [], []
    for i in range(n):
        for j in range(m):
            if a[i][j] == 1:
                l.append(i)
                r.append(j)
    D = min(len(set(l)), len(set(r)))
            
            
    if D % 2 == 0:
        print('Vivek')
    else:
        print('Ashish')
        
