s, x1, x2 = map(int, input().split())
t1, t2 = map(int, input().split())
p, d = map(int, input().split())

def solve(s, x1, x2, t1, t2, p, d):
    ans = abs(x2 - x1) * t2

    if t1 > t2:
        return ans
    
    if x1 < x2:
        if p <= x1:
            return min(ans, (x2 - p * d) * t1)
        else:
            if d == 1:
                return min(ans, (s - p + s + x2) * t1)
            else:
                return min(ans, (p + x2) * t1)
    else:
        if p < x1:
            return min(ans, (2 * s - p * d - x2) * t1)
        else:
            if d == 1:
                return min(ans, (s - p + s - x2) * t1)
            else:
                return min(ans, (p - x2) * t1)
    
print(solve(s, x1, x2, t1, t2, p, d))


