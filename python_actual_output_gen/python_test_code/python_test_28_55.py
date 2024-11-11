import sys

s = sys.stdin.readline()

def check_upper(c):
    if c >= 'A' and c <= 'Z':
        return True
    else:
        return False

upper_count = 0

for ch in s:
    if(check_upper(ch)):
        upper_count += 1
    else:
        upper_count -= 1

if(upper_count > 0):
    s = s.upper()
else:
    s = s.lower()

print(s)