n = int(input())
c = 0
s = 0
packs = 0
while n>s:
    packs += 1
    c+=1
    s += c
print(packs)