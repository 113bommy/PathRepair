
def read():
    return [int(x) for x in input().split()]


k,n = read()
a = read()
b = read()

sum = set()
tmp =[0]
for e in a:
    tmp.append(tmp[-1]+e)
    sum.add(tmp[-1])

ans = set()
for e in tmp:
    init = b[0]-e
    for bb in b[1:]:
        if bb - init not in sum:
            break
    else:
        ans.add(init)

print(len(ans))