m = a = 0
for c in input():
    if c in "ATGC": m+=1
    else: a = max(a, m); m = 0
else: print(a)