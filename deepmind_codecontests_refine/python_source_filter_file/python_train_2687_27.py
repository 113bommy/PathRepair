import re
regex=(r'[A|C|G|T]+')
s=input()
mo=re.findall(regex,s)
print(len(max(mo)) if mo!=[] else 0)