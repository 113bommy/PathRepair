import re

for _ in range(8):
    if re.match('WW|BB', input()) is not None:
        print('NO')
        exit()
print('YES')