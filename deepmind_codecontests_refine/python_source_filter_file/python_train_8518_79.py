import re
s = input()

pattern = r"A?KIHA?BA?RA?"

print("Yes" if re.search(pattern, s) else "No")