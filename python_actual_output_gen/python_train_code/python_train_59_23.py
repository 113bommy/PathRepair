# @author: guoyc
# @date: 2018/7/20

res = 0

n = 0

import sys

for s in sys.stdin:
    if s[0] == '+':
        n += 1
    elif s[0] == '-':
        n -= 1
    elif s.find(':') != -1:
        name, msg = s.split(':')
        res += n * len(msg)

print(res)
