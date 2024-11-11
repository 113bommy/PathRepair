import re

s = input()
cf = "CODEFORCES"
for i in range(len(cf)+1):
    pat = cf[:i] + ".*" + cf[i:]
    if re.search(pat, s):
        print("YES")
        break
else:
    print("NO")

