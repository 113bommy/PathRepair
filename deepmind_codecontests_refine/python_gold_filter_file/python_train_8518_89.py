import re
s = input()
ans = 'YES' if re.match(r'^A{0,1}KIHA{0,1}BA{0,1}RA{0,1}$', s) else 'NO'
print(ans)
