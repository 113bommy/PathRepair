n = int(input())
v = list(map(int, input().split()))
def doit(vs):
    ret = {}
    for v in vs:
        ret[v] = ret.get(v, 0) + 1
    return sorted((-ret[v], v) for c in ret) + [(0, None)]
odd = doit(v[0::2])
even = doit(v[1::2])
if odd[0][1] != even[0][1]:
    print(n + odd[0][0] + even[0][0])
else:
    print(n + min(odd[1][0] + even[0][0], odd[0][0] + even[1][0]))
