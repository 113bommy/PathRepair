import re
while True:
    s = input()
    if (re.match(r'.+\s\?\s.+', s)):
        break
    print(int(eval(s)))