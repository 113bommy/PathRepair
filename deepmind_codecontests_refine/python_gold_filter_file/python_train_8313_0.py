import re
import sys
for s in sys.stdin:
    print(re.sub(r"@(\d)(.)", lambda m: m.group(2)*int(m.group(1)), s.rstrip()))
