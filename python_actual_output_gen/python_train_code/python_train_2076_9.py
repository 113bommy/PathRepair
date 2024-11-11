import sys

N = int(input())
C = [0]
for line in sys.stdin:
    c = int(line)
    if c[-1] == c:
        continue
    else:
        C.append(c)

ans = 1
dic = {}
for c in C:
    if c in dic.keys():
        a = dic[c]
        dic[c] += ans
        ans += a
    else:
        dic[c] = ans

print(ans % (10 ** 9 + 7))