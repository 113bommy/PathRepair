a, b = map(int,input().split())
if a < b: a,b=b,a
if a == b: print(0); exit()

def update(g):
    global ans
    # a+n must be a multiple of g, and so is b+n
    if a%g != b%g: return
    n = g - a%g if a%g else 0
    lcm = (a+n)*(b+n)//g
    ans = min(ans, (lcm, n))

d = a-b
ans = (10**31, 10**31) # lcm, N
for gcd in range(1, int(d**.5)+2):
    if d%gcd: continue
    update(gcd)
    update(d // gcd)
print(ans[1])