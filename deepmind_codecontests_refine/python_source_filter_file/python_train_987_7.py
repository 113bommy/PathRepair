n, d = [int(x) for x in input().split()]
dict = {}
for i in range (n):
    m, s = [int(x) for x in input().split()]
    if dict.get(m) == None:
        dict[m] = s
    else:
        dict[m] += s
sortedKeys = sorted(dict.keys())
leng = len(sortedKeys)
s = 0
r = 0
while r < leng:
    if sortedKeys[r] <= sortedKeys[0] + d:
        s += dict.get(sortedKeys[r])
        r += 1
    else:
        break
maxValue = s
for i in range (1, leng):
    l = i - 1
    s -= dict.get(sortedKeys[l])
    while r < leng and sortedKeys[i] + d >= sortedKeys[r]:
        s += dict.get(sortedKeys[r])
        r += 1
    maxValue = max(maxValue, s)
    if r == leng:
        break
print(maxValue)