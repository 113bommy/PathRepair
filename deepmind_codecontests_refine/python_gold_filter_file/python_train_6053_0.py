c1,c2,c3,c4 = [int(input()) for i in range(4)]
out = 0
if c1 != c4:
    out = 0
elif c3 > 0:
    if c1 > 0 and c4 > 0:
        out = 1
    else:
        out = 0
else:
    out = 1
print(out)