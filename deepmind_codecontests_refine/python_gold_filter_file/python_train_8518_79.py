# 2019/08/08

import re
s=input()
res=re.search(r'^A?KIHA?BA?RA?$',s)
print('YES' if res  else 'NO')