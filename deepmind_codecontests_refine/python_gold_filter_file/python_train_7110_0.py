from sys import stdin
n1, n2, n3, n4 = map(int, stdin.readline().split())
p1 = sorted(zip(map(int, stdin.readline().split()), range(1, n1+1)))
p2 = sorted(zip(map(int, stdin.readline().split()), range(1, n2+1)))
p3 = sorted(zip(map(int, stdin.readline().split()), range(1, n3+1)))
p4 = sorted(zip(map(int, stdin.readline().split()), range(1, n4+1)))
m1 = int(stdin.readline())
b1 = set()
for _ in range(m1):
    b1.add(tuple(map(int, stdin.readline().split())))
m2 = int(stdin.readline())
b2 = set()
for _ in range(m2):
    b2.add(tuple(map(int, stdin.readline().split())))
m3 = int(stdin.readline())
b3 = set()
for _ in range(m3):
    b3.add(tuple(map(int, stdin.readline().split())))

def f(pa, pb, b):
    output = []
    for j in range(len(pb)):
        pricej, idxj = pb[j]
        for i in range(len(pa)):
            pricei, idxi = pa[i]
            if (idxi, idxj) not in b:
                output.append((pricei+pricej, idxj))
                break
    return sorted(output)

o1 = f(p1, p2, b1)
o2 = f(o1, p3, b2)
o3 = f(o2, p4, b3)
if o3:
    print(min(o3)[0])
else:
    print(-1)
