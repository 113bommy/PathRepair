x = int(input())
n = 0
if x % 11 > 6:
    n += 2
elif x % 11 > 0:
    n += 1
print(x//11*2+n)
