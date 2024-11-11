n, h = map(int, input().split())

base = h * (h + 1) // 2

if n <= base:
    lo = 0
    hi = h + 1
    while lo < hi:
        mi = (lo + hi) // 2
        if mi * (mi + 1) / 2 >= n:
            hi = mi
        else:
            lo = mi + 1
    print(lo)
    
else:
    lo = 1
    hi = 10 ** 20
    
    def get(x):
        res = 0
        res += base
        res += x * h
        y = x - 1
        top = (y + 1) // 2
        if y % 2 == 1:
            # [1..top-1][top][top-1..1]
            res += top * (top - 1)
            res += top
        else:
            # [1..top][top..1]
            res += top * (top + 1)
        return res
    
    while lo < hi:
        mi = (lo + hi) // 2
        if get(mi) >= n:
            hi = mi
        else:
            lo = mi + 1
    print(lo + h)
  