n, m, r = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
s = [int(x) for x in input().split()]
mn = min(b)
mx = max(s)
if mx > mn and r > mn:
    q, r = divmod(r, mn)
    r += q * mx
print(r)