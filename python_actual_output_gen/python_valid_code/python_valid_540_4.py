for i in range(int(input())):
    k = int(input())
    c = (k-1)**0.5//1+1
    if k-((c-1)**2+1) != c**2-k:
        col = min(max((c)**2-k,1),c)
        row = min(max(k-(c-1)**2,1),c)
        print(int(row), int(col))
    else:
        print(int(c), int(c))
