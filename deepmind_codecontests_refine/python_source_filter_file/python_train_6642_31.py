s = input()
ans = 'NA'
if 1 <= int(s[:2]) <= 12:
    ans = 'MMYY'
    if 1 <= int(s[2:]) <= 12:
        ans = 'ANBIGUOUS'
elif 1 <= int(s[2:]) <= 12:
    ans = 'YYMM'
print(ans)