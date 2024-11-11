import re


s = input()
if s[0] == "A" and s[2:-2].count("C") == 1 and len(re.findall('[A-Z]', s)) == 2:
    print("AC")
else:
    print("WA")