from math import ceil
hh, mm = input().split()
H, D, C, N = input().split()
t20 = 20 * 60
time = int(hh) * 60 + int(mm)
if t20 <= time:
    res = ceil(int(H)/int(N)) * float(C)
else:
    res1 = ceil(int(H)/int(N)) * float(C)
    res2 = ceil(((t20 - time) * int(D) + int(H)) / int(N)) * float(C) * 0.8
    res = min(res1, res2)
res = round(res, 3)
print(res)