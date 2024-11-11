s = input()
res = 10**10
for i in range(10**6):
    if i * i > int(s):
        break
    
    t = str(i * i)
    p = 0
    for x in s:
        if x == t[p]:
            p += 1
            if p == len(t):
                break
    
    if p == len(t):
        res = min(res, len(s) - len(t))

if res == 10**10:
    res = -1
print(res)