a, b, c = (input() for _ in range(3))
d = {"a": a, "b": b, "c": c}
nex = "a"

while len(d[nex]) != 0:
    tmp = d[nex][0]
    d[nex] = d[nex][1:]
    nex = tmp

print(nex)