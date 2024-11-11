import re
s=input()
print(["Too weak","Correct"][all([len(s)>=6,re.search(r'[a-z]', s),re.search(r'[A-Z]', s),re.search(r'\d', s)])])