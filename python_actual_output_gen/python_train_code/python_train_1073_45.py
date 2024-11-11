import re
input()
print(re.sub('(?<=[aeiou])[aeiou]+', '', input()))