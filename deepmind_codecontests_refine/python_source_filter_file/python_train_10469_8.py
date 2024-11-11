str = input()
res = 0
lastSmb = 0

for smb in str:
    sid = ord(smb) - ord('a')
    diff = sid - lastSmb
    if diff < 0:
        diff = -diff

    if diff > 14:
        diff = 26 - diff

    res += diff
    lastSmb = sid

print(res)