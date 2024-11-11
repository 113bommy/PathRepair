import re
S = input()

print(["YES", "NO"][not(re.search("^A?KIHA?BA?RA?$", S))])
