n = int(input())
a = [int(x) for x in input().split()]

b = {}
for t in a:
    if t in b:
        b[t] += 1
    else:
        b[t] = 1

dva =[]
for i in range(31):
    dva.append(2**i)

m = 0
for d in dva:
    for k in b.keys():
        if (k < d):
            if not k == d // 2:
                if d - k in b:
                    m += b[k] * b[d - k]
            else:
                m += b[k] * (b[k] - 1)
                
print(m // 2)

