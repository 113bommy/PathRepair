import re

n = input()

mat = re.compile(r"(^1$)|(^[1]+[41]{0,2}$)+")
res = mat.search(n)

if res:
    print ("YES")
else:
    print ("NO")