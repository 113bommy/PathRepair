def check(i):
    k = 0
    for c, n in zip(s, ns):
        if n<=i: continue
        if s2[k] == c:
            k+=1
            if k == len(s2):
                return True
    return False
s = input()
s2 = input()
ns = [(i, int(x)) for i, x in enumerate(input().split())]
ns.sort(key=lambda x: x[1])
ns = [x[0] for x in ns]
l = 0
r = len(s)
while(r-l>1):
    i = (r+l) // 2
    if check(i):
        l = i
    else:
        r = i
print(l+1)