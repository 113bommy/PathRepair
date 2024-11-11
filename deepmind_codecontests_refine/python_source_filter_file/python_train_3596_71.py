import sys

n, x = map(int, input().split())
packs = x
d_kids = 0

for _ in range(n):
    char, d = sys.stdin.readline().split()
    if char == "+":
        packs += int(d)
    elif char == "-":
        if packs > int(d):
            packs -= int(d)
        else:
            d_kids += 1

print(packs, d_kids)