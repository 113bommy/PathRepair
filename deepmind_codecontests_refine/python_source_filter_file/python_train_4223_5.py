

def easy(vals):
    d = int(vals[0])
    k = int(vals[1])
    a = int(vals[2])
    b = int(vals[3])
    t = int(vals[4])
    if d <= k:
        return d*a
    sofar = k
    left = d-k
    if b*k < a*k + t:
        return sofar*a + left*b
    if left > k:
        sofar = sofar*a + (left//k)*(a*k + t)
        left = left % k
    if left*b <= left*a + t:
        return sofar + left*b
    return sofar + left*a + t


vals = input().split()
print(easy(vals))
