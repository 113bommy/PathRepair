l,r = [int(_) for _ in input().split()]
if l % 2 != 0:
    l += 1
if r-l < 2:
    print(-1)
else:
    print(l,l+1,r)
