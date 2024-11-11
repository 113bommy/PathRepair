# from collections import *

s = str(input()); t = str(input())
num = 0

for i in range(len(s)):
    # print(len(s) - i - 1) + s[len(s) - i - 1]

    if s[len(s) - i - 1] == t[len(t) - i - 1] and len(t) - i - 1 >= 0:
        num += 1
    else:
        break
print (num)

print (len(s) + len(t) - 2 * num)
