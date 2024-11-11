def solve(hi,lo):
    for j in range(1000):
        mid = lo + (hi - lo) / 2
        rest = d - mid
        if abs(mid + rest - mid*rest) <= 10**-6 and abs(mid + rest - d) <= 10**-6:
            return "Y {:.9f} {:.9f}".format(rest, mid)
        if mid*rest > d:
            hi = mid
        else:
            lo = mid
    return "N"

for i in range(int(input())):
    d = int(input())
    print(solve(d,0))


    
            
        
