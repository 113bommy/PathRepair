import re
print(max(map(len,re.finditer('[ACGT]*',input()))))