s = input()
rs = [(ord(c) - ord('0')) % 3 for c in s]

res = 0

curRem = 0
curCount = 0
for rem in rs:
    if rem == 0:
        res += 1
        curRem = 0
        curCount = 0
    else:
        curRem += rem
        curCount += 1
        if curRem == 0 or curCount >= 3:
            res += 1
            curRem = 0
            curCount = 0

print(res)