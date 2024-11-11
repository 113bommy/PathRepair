import re
s = input()

pattern = r"^A?KIHA?BA?RA?$"

print("YES" if re.search(pattern, s) else "NO")