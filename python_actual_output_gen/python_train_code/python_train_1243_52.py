# import os


n, x = map(int, input().split())

distress = 0
ices = 0

for _ in range(n):
    s = input()
    if s[0] == '+':
        ices += int(s[2:])
    else:
        if ices >= int(s[2:]):
            ices -= int(s[2:])
        else:
            distress += 1
print("{} {}".format(ices, distress))


# 03/01 - 1
# 04/01 - 21
# 05/01 - 27
# 06/01 - 2

