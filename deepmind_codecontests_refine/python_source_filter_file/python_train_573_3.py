#M16_A

ln = [int(i) for i in input().split(" ")]

a = ln[0]
b = ln[1]
c = ln[2]

f = False
wds = ["No", "Yes"]

for i in range(0, c, a):
    for j in range(0, c, b):
        if i + j == c:
            f = True

print(wds[f])
