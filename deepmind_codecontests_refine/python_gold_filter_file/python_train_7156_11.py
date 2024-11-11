s = input()
S = s.lower()
if 'abc' in S or 'bac' in S or 'cab' in S or 'cba' in S or 'acb' in S or 'bca' in S:
    print("Yes")
else:
    print("No")