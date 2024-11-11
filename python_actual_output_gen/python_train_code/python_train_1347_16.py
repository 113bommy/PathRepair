n = int(input())
s = str(n)
l = len(s)
maxpos = 0
for i in range(1,l+1):
    maxpos += 2**i
pos = maxpos

s = s[::-1]
for i,c in enumerate(s):
    if c in "4":
        pos -= (i+1)
print(pos)