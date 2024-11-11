import re
pattern = '^A?KIHA?BA?RA?'
print("YES" if re.match(pattern,input()) else "NO")