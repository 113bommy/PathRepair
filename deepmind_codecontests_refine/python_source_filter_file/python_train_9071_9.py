l, r = map(int, input().split())
mod = 1000000007

o = e = 0
x = i = 1
while x < l:
    if i % 2: e += x//2
    else: o += x//2
    
    if (x << 1) < l: x = x << 1
    else:
        if i % 2: o += l-x
        else: e += l-x
        break
    i += 1

s1 = (e*(e+1) + o*o) % mod
o = e = 0
x = i = 1
while x < r:
    if i % 2: e += x//2
    else: o += x//2
    
    if (x << 1) < r: x = x << 1
    else:
        if i % 2: o += r-x+1
        else: e += r-x+1
        break
    i += 1

s2 = (e*(e+1) + o*o) % mod
print(((s2 - s1 % mod) + mod) % mod)
