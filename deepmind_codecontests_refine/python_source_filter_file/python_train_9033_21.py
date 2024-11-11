n,k,*h=map(int,open(0).read().split())
if k>=n:
    print(0)
else:
    h.sort
    print(sum(h[:n-k]))