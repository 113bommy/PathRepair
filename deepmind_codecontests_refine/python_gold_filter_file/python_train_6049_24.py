import math

n, a, b = list(map(int, input().split()))
o = 0
mi = min(a,b)
s = list(map(int, input().split()))

for i in range(0, len(s) // 2):

    if s[i] == 2 and s[-i - 1] == 2:
        o += mi * 2

    elif (s[i] == 1 and s[-i - 1] == 2) or (s[i] == 2 and s[-i - 1] == 1):
        o += b

    elif (s[i] == 0 and s[-i - 1] == 2) or (s[i] == 2 and s[-i - 1] == 0):
        o += a

    elif (s[i] == 1 and s[-i - 1] == 0) or (s[i] == 0 and s[-i - 1] == 1):
        print(-1)
        exit()

if len(s) % 2 == 1:
    if s[len(s) // 2] == 2:
        o += mi

print(o)