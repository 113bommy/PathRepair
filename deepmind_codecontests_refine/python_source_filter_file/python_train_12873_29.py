import math
k, n, s, p = map(int, input().split())
def paper_planes(k,n,s,p):
    min_packs=math.ceil(n/s)*(k/p)
    if (min_packs<1):
        min_packs=k
        print(min_packs)
    else:
        min_packs=math.ceil(min_packs)
        print(min_packs)
paper_planes(k,n,s,p)
    



