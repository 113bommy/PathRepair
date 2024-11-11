s = input()
S = s.lower()
if 'abc' in s or 'bac' in s or 'cab' in s or 'cba' in s or 'acb' in s or 'bca' in s:
    print("Yes")
else:
    print("No")