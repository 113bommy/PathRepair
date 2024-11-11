val = 0
for ch in input():
    val = (val * 32 + '><+-.,[]'.find(ch) + 8) % 1000003
print(val)
