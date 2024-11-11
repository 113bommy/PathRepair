import re
s = input()
print('YES') if re.fullmatch('(maerd|remaerd|esare|resare)+', s[::-1]) else print('NO')