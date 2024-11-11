import re
s = input()
print(max(map(len, re.split('R', s))))