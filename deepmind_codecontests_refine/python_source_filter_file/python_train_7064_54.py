import re
print("YNEOS"[not re.match('.*C.*F',input())::2])