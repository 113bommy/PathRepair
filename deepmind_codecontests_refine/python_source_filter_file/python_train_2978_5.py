n,s = map(int,input().split())

def diff(m):
    return m - sum([int(k) for k in list(str(m))])
    
def digit_safe(k):
    r = len(list(str(k)))
    return toint(["1"]+["0"]*(r-1))
a = list(str(n))
b = list(str(s))
d = int(a[0])

def toint(l):
    return int("".join(l))
res = 0
for i in range(d):
    z = toint([str(i)] + ["0" for _ in range(len(a)-1)])
    z1 = toint([str(i+1)] + ["0" for _ in range(len(a)-1)])
    count = diff(z)
    while z < z1 and count < s:
        z += digit_safe(count)
        count = diff(z)
    if z <= z1:
        res += (z1-z)
z = toint([str(d)] + ["0" for _ in range(len(a)-1)])
z1 = n+1
count = diff(z)
while z < z1 and count < s:
    z += digit_safe(count)
    count = diff(z)
if z <= z1:
    res += (z1-z)
print(res)
