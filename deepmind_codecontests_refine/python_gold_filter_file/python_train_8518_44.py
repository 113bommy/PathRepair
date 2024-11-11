import re
print("YNEOS"[not re.fullmatch("A?KIHA?BA?RA?", input())::2])