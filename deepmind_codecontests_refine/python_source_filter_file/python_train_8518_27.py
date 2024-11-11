import re
pattern = '^A?KA?IA?HA?BA?RA?$'
print("YES" if re.match(pattern,input()) else "NO")