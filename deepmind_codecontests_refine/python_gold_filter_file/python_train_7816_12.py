# cf 1025 A 900
n = input()
s = input()
hc = {}

for c in s:
    hc[c] = hc.get(c, 0) + 1

m2, m1 = 0, 0
for ch in s:
    c = hc[ch]
    if c >= 2:
        m2 += 1
    else:
        m1 += 1

if len(hc) == 1 or m2 >= 1:
    print("Yes")
else:
    print("No")
        
