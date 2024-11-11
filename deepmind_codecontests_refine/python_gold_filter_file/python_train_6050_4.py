n = input()
s = input()

d = dict()
for i in s:
    d[i] = d.get(i, 0) + 1

st = ''
for key in d.keys():
    st += key * d[key]
print(st)