import random
def xor_v(a):
    res = 0
    for i in a:
        res ^= i
    return res

a, b = list(map(int, input().split()))
m = []
for i in range(a):
    m.append(list(map(int, input().split())))

i = 0
res = 0
while i < 800 and res == 0:
    i+=1
    v = []
    x = []
    for j in range(a):
        idx = random.randint(0, b-1)
        v.append(m[j][idx])
        x.append(idx + 1)
    res = xor_v(v)
    if res > 0:
        print("TAK")
        print(" ".join(list(map(str, x))))
        exit(0)
print("NIE")