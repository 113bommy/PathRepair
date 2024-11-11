import math

s = input().strip()


mn = []

for m in range(1 << len(s)):
    make = []
    for i in range(len(s)):
        if m & (1 << i):
            make += [s[i]]
    x = ''.join(make)
    # print(make)
    if len(x) == 0:
        x = '0'
        continue
    cum = int(x)
    if cum == 0:
        continue
    if math.ceil(math.sqrt(cum)) == math.floor(math.sqrt(cum)):
        mn += [''.join(make)]


for i, val in enumerate(mn):
    if len(val) == 0:
        val = '0'
        continue
    mn[i] = str(int(val))

mn.sort(key=lambda x: len(x))
# print(mn)
print(len(s) - len(mn[-1]) if len(mn) else -1)