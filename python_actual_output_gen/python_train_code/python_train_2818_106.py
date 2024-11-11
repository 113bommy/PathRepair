x = int(input())
n = 0
if x % 11 < 5:
    n += 1
elif x % 11 >= 5:
    n += 2

print((x//11)*2+n)
