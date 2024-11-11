import re
a=input()
ex=re.compile('^(1|14|144)+')
print("YES" if re.search(ex,a) else "NO")