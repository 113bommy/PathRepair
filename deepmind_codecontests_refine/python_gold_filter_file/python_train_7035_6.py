from sys import stdin
t = input().strip()
p = input().strip()

def possible(pos):
    it = 0
    ip = 0
    while it < len(t) and ip < len(p):
        if it in d:
            it += 1
            continue
        if t[it] == p[ip]:
            it += 1
            ip += 1
        else:
            it += 1
    if ip == len(p):
        return True
    else:
        return False


a = [int(x)-1 for x in stdin.readline().split()]
l = 0
r = len(t) - len(p)
d = set()
while l < r:
    mid = (l + r) // 2
    if len(d) < (mid + 1):
        for i in range(len(d), mid + 1):
            d.add(a[i])
    else:
        for i in range(mid + 1, len(d), 1):
            d.discard(a[i])
    if possible(mid):
        l = mid + 1
    else:
        r = mid
print(l)
