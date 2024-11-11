import re
S = input().strip()
print('AC' if re.match(r'^A[a-z]*C[a-z]*$', S) else 'WA')