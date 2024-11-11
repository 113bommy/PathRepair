dict = {}
n,m = [int(i) for i in input().split()]
for _ in range(m):
    test = [i for i in input().split()]
    if len(test[0]) < len(test[1]):
        dict[test[1]] = test[0]
    else:
        dict[test[0]] = test[1]
res = ""
for e in input().split():
    if e in dict:
        res+=dict[e]
    else:
        res+=e
    res+=" "
print(res)
